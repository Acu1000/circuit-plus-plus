#include<comps/acpower.hpp>
#include<simulation/circuit.hpp>
#include<simulation/mna_equation.hpp>

ACPower::ACPower(ComponentID p_id) : Component(p_id, 2), func([](real_t){return 0;}) {
}

void ACPower::build(ComponentBuildDto dto)
{
    if (dto.circuit.is_terminal_connected(Plus.get_id()) || dto.circuit.is_terminal_connected(Minus.get_id())) {
        voltage_source_id = dto.equation.add_voltage_source();
        dto.equation.set_source_voltage(voltage_source_id, 0);

        if (dto.circuit.is_terminal_connected(Plus.get_id())) {
            dto.equation.set_connection(dto.circuit.get_terminal_node(Plus.get_id()), voltage_source_id, +1);
        }

        if (dto.circuit.is_terminal_connected(Minus.get_id())) {
            dto.equation.set_connection(dto.circuit.get_terminal_node(Minus.get_id()), voltage_source_id, -1);
        }
    }
}

void ACPower::update(ComponentUpdateDto dto) {
    last_voltage = func((dto.elapsed_steps+1) * dto.dt);
    dto.equation.set_source_voltage(voltage_source_id, last_voltage);
}

void ACPower::set_sine_wave(real_t p_amplitude, real_t p_frequency, real_t p_shift) {
    func = [=](real_t t){return std::sin(M_PI * 2 * (t * p_frequency + p_shift)) * p_amplitude;};
}

real_t ACPower::get_voltage() { return last_voltage; }