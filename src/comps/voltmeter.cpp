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

void Voltmeter::update(Circuit &p_circuit, MNAEquation &p_equation, real_t)
{
    double plus_voltage = 0;
    double minus_voltage = 0;

    TerminalID plus_terminal_id = Plus.get_id();
    if (p_circuit.is_terminal_connected(plus_terminal_id)) {
        int plus_node_id = p_circuit.get_terminal_node(plus_terminal_id);
        plus_voltage = p_equation.get_node_voltage(plus_node_id);
    }

    TerminalID minus_terminal_id = Minus.get_id();
    if (p_circuit.is_terminal_connected(minus_terminal_id)) {
        int minus_node_id = p_circuit.get_terminal_node(minus_terminal_id);
        minus_voltage = p_equation.get_node_voltage(minus_node_id);
    }
    
    last_voltage = plus_voltage - minus_voltage;
}
