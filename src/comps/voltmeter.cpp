#include<comps/voltmeter.hpp>
#include<simulation/mna_equation.hpp>
#include<simulation/circuit.hpp>

Voltmeter::Voltmeter(ComponentID p_id) : Component(p_id, 2)
{
}

real_t Voltmeter::measure()
{
    return last_voltage;
}

void Voltmeter::update(Circuit &p_circuit, MNAEquation &p_equation)
{
    int plus_node_id = p_circuit.get_terminal_node(Plus.get_id());
    int minus_node_id = p_circuit.get_terminal_node(Minus.get_id());
    last_voltage = p_equation.get_node_voltage(plus_node_id) - p_equation.get_node_voltage(minus_node_id);
}
