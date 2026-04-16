#include<simulation/simulation_builder.hpp>
#include<simulation/simulation.hpp>

SimulationBuilder* SimulationBuilder::instance = nullptr;

SimulationBuilder::SimulationBuilder() {
    
}

NodeID SimulationBuilder::create_node()
{
    NodeID id = nodes.size();
    Node new_node(id);
    nodes.push_back(new_node);
    return id;
}

Simulation SimulationBuilder::build() {
    Simulation sim(nodes.size());

    for (const auto& comp : components) {
        comp->build(*this, sim);
    }

    return sim;
}

bool SimulationBuilder::is_terminal_connected(TerminalID p_terminal)
{
    return terminal_connections.contains(p_terminal);
}

NodeID SimulationBuilder::get_terminal_node(TerminalID p_terminal)
{
    if (!is_terminal_connected(p_terminal)) {
        cerr << "ERROR: attempted to get unconnected terminal node\n";
        exit(1);
    }
    return terminal_connections.at(p_terminal);
}

void SimulationBuilder::set_terminal_node(TerminalID p_terminal, NodeID p_node)
{
    terminal_connections.insert({p_terminal, p_node});
}

void SimulationBuilder::connect(Terminal p_t1, Terminal p_t2)
{
    TerminalID t1id = p_t1.get_id();
    TerminalID t2id = p_t2.get_id();

    if (is_terminal_connected(t1id) && is_terminal_connected(t2id)) {
        // TODO: implement node merging
        cerr << "NOT IMPLEMENTED: both terminals already have nodes\n";
        exit(1);
    }
    else if (is_terminal_connected(t1id)) {
        NodeID other_node = get_terminal_node(t1id);
        set_terminal_node(t2id, other_node);
    }
    else if (is_terminal_connected(t2id)) {
        NodeID other_node = get_terminal_node(t2id);
        set_terminal_node(t1id, other_node);
    }
    else {
        NodeID new_node = create_node();
        set_terminal_node(t1id, new_node);
        set_terminal_node(t2id, new_node);
    }
}

