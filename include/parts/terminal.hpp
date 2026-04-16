#pragma once

#include<global.hpp>

class Terminal {
    private:
    TerminalID id;

    public:
    Terminal(ComponentID p_owner_id, TerminalSubID p_id);

    TerminalID get_id() const;

    bool operator==(const Terminal& other) const {
        return id == other.get_id();
    }
};

template<>
struct std::hash<Terminal>{
    size_t operator()(const Terminal& p) const {
        return std::hash<TerminalID>{}(p.get_id());
    }
};