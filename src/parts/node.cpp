#include "parts/node.hpp"
#include "parts/terminal.hpp"

Node::Node(NodeID p_id) : id(p_id)
{
}

void Node::add_terminal(Terminal p_terminal)
{
    terminals.insert(p_terminal);
}

bool Node::has_terminal(Terminal p_terminal)
{
    return terminals.contains(p_terminal);
}

void Node::remove_terminal(Terminal p_terminal)
{
    terminals.erase(p_terminal);
}
