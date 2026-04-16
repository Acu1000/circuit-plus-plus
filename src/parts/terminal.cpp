#include<parts/terminal.hpp>
#include<simulation/simulation_builder.hpp>

Terminal::Terminal(ComponentID p_owner_id, TerminalSubID p_sub_id) : id(p_owner_id, p_sub_id)
{
}

TerminalID Terminal::get_id() const { return id; }

/*
bool Terminal::has_node() { return node_id != -1; }

int Terminal::get_node_id() { return node_id; }

void Terminal::set_node_id(NodeID p_node_id) { node_id = p_node_id; }

void Terminal::connect(Terminal& other)
{
    if (has_node() && other.has_node()) {
        // TODO: implement node merging
        cerr << "NOT IMPLEMENTED: both terminals already have nodes\n";
        exit(1);
    }
    else if (has_node()) {
        other.set_node(get_node());
        get_node().add_terminal(other);
    }
    else if (other.has_node()) {
        Node& other_node = other.get_node();
        set_node(other_node);
        other_node.add_terminal(*this);
    }
    else {
        Node& new_node = SimulationBuilder::get()->create_node();
        set_node(new_node);
        other.set_node(new_node);
        new_node.add_terminal(*this);
        new_node.add_terminal(other);
    }
}
*/