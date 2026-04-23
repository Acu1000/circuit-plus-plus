#include<comps/dcpower.hpp>
#include<simulation/simulation.hpp>

DCPower::DCPower(ComponentID p_id, real_t p_voltage) : Component(p_id), voltage(p_voltage) {}

void DCPower::build(ComponentBuildDto dto)
{
    if (dto.circuit.is_terminal_connected(Plus.get_id()) || dto.circuit.is_terminal_connected(Minus.get_id())) {
        voltage_source_id = dto.equation.add_voltage_source();
        dto.equation.set_source_voltage(voltage_source_id, voltage);

        if (dto.circuit.is_terminal_connected(Plus.get_id())) {
            dto.equation.set_connection(dto.circuit.get_terminal_node(Plus.get_id()), voltage_source_id, +1);
        }

        if (dto.circuit.is_terminal_connected(Minus.get_id())) {
            dto.equation.set_connection(dto.circuit.get_terminal_node(Minus.get_id()), voltage_source_id, -1);
        }
    }
}