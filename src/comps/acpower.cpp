#include<comps/acpower.hpp>
#include<simulation/circuit.hpp>
#include<simulation/mna_equation.hpp>

ACPower::ACPower(ComponentID p_id) : Component(p_id, 2), func([](real_t){return 0;}) {

}

void ACPower::build(Circuit& p_circuit, MNAEquation &p_equation)
{
    if (p_circuit.is_terminal_connected(Plus.get_id()) || p_circuit.is_terminal_connected(Minus.get_id())) {
        voltage_source_id = p_equation.add_voltage_source();
        p_equation.set_source_voltage(voltage_source_id, 0);

        if (p_circuit.is_terminal_connected(Plus.get_id())) {
            p_equation.set_connection(p_circuit.get_terminal_node(Plus.get_id()), voltage_source_id, +1);
        }

        if (p_circuit.is_terminal_connected(Minus.get_id())) {
            p_equation.set_connection(p_circuit.get_terminal_node(Minus.get_id()), voltage_source_id, -1);
        }
    }
}

void ACPower::update(Circuit&, MNAEquation& p_equation, real_t dt) {
    p_equation.set_source_voltage(voltage_source_id, func(t_elapsed));
    t_elapsed += dt;
}

void ACPower::set_sine_wave(real_t p_amplitude, real_t p_frequency, real_t p_shift) {
    func = [=](real_t t){return std::sin(t * p_frequency + p_shift) * p_amplitude;};
}