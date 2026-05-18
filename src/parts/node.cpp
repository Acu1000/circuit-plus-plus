#include "parts/node.hpp"
#include "parts/terminal.hpp"

Node::Node(NodeID p_id) : id(p_id)
{
}

void Node::add_terminal(TerminalID p_terminal)
{
    terminals.insert(p_terminal);
}

bool Node::has_terminal(TerminalID p_terminal)
{
    return terminals.contains(p_terminal);
}

void Node::remove_terminal(TerminalID p_terminal)
{
    terminals.erase(p_terminal);
}
