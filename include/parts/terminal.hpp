#pragma once

#include<global.hpp>

class Terminal {
    private:
    TerminalID id;

    public:
    Terminal(ComponentID p_owner_id, TerminalSubID p_id);

    TerminalID get_id() const;

    Terminal(const Terminal&) = delete;
    Terminal& operator=(const Terminal&) = delete;

    Terminal(Terminal&&) = default;
    Terminal& operator=(Terminal&&) = default;
};