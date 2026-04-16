#include<comps/resistor.hpp>
#include<simulation/simulation.hpp>
#include<simulation/simulation_builder.hpp>
#include<parts/node.hpp>

Resistor::Resistor(ComponentID p_id, real_t p_resistance) : Component(p_id), resistance(p_resistance)  {
    
}

void Resistor::build(SimulationBuilder& builder, Simulation& sim)
{
    if (builder.is_terminal_connected(A.get_id())) {
        NodeID node_a_id = builder.get_terminal_node(A.get_id());
        sim.add_base_conductance(node_a_id, node_a_id, 1.0 / resistance);
    }
    if (builder.is_terminal_connected(B.get_id())) {
        NodeID node_b_id = builder.get_terminal_node(B.get_id());
        sim.add_base_conductance(node_b_id, node_b_id, 1.0 / resistance);
    }
    if (builder.is_terminal_connected(A.get_id()) && builder.is_terminal_connected(B.get_id())) {
        NodeID node_a_id = builder.get_terminal_node(A.get_id());
        NodeID node_b_id = builder.get_terminal_node(B.get_id());
        sim.add_base_conductance(node_a_id, node_b_id, -1.0 / resistance);
        sim.add_base_conductance(node_b_id, node_a_id, -1.0 / resistance);
    }
}