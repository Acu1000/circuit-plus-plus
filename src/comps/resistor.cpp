#include<comps/resistor.hpp>
#include<simulation/simulation.hpp>
#include<parts/node.hpp>

Resistor::Resistor(ComponentID p_id, real_t p_resistance) : Component(p_id), resistance(p_resistance)  {
    
}

void Resistor::build(ComponentBuildDto dto)
{
    if (dto.circuit.is_terminal_connected(A.get_id())) {
        NodeID node_a_id = dto.circuit.get_terminal_node(A.get_id());
        dto.equation.add_static_conductance(node_a_id, node_a_id, 1.0 / resistance);
    }
    if (dto.circuit.is_terminal_connected(B.get_id())) {
        NodeID node_b_id = dto.circuit.get_terminal_node(B.get_id());
        dto.equation.add_static_conductance(node_b_id, node_b_id, 1.0 / resistance);
    }
    if (dto.circuit.is_terminal_connected(A.get_id()) && dto.circuit.is_terminal_connected(B.get_id())) {
        NodeID node_a_id = dto.circuit.get_terminal_node(A.get_id());
        NodeID node_b_id = dto.circuit.get_terminal_node(B.get_id());
        dto.equation.add_static_conductance(node_a_id, node_b_id, -1.0 / resistance);
        dto.equation.add_static_conductance(node_b_id, node_a_id, -1.0 / resistance);
    }
}