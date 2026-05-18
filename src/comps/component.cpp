#include<comps/component.hpp>

Component::Component(ComponentID p_id, int p_terminal_count) : id(p_id), terminal_count(p_terminal_count)
{
    for (TerminalSubID i=0; i<terminal_count; i++) {
        terminals.emplace(terminals.end(), id, i);
    }
}
