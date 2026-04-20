#include<comps/dcpower.hpp>
#include<simulation/simulation.hpp>

DCPower::DCPower(ComponentID p_id, real_t p_voltage) : Component(p_id), voltage(p_voltage) {}

void DCPower::build(Circuit& p_circuit, MNAEquation &p_equation)
{
    if (p_circuit.is_terminal_connected(Plus.get_id()) || p_circuit.is_terminal_connected(Minus.get_id())) {
        voltage_source_id = p_equation.add_voltage_source();
        p_equation.set_source_voltage(voltage_source_id, voltage); // TODO: might have to make this dynamic instead

        if (p_circuit.is_terminal_connected(Plus.get_id())) {
            p_equation.set_connection(p_circuit.get_terminal_node(Plus.get_id()), voltage_source_id, +1);
        }

        if (p_circuit.is_terminal_connected(Minus.get_id())) {
            p_equation.set_connection(p_circuit.get_terminal_node(Minus.get_id()), voltage_source_id, -1);
        }
    }
}