#include<parts/terminal.hpp>

Terminal::Terminal(ComponentID p_owner_id, TerminalSubID p_sub_id) : id(p_owner_id, p_sub_id)
{
}

TerminalID Terminal::get_id() const { return id; }

