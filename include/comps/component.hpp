#pragma once

#include<global.hpp>
#include<parts/terminal.hpp>
#include<array>

class MNAEquation;
class Circuit;

class Component {
    protected:
    ComponentID id;
    int terminal_count;
    std::vector<Terminal> terminals;

    Component(ComponentID id, int p_terminal_count=2);

    public:
    virtual void build(Circuit&, MNAEquation&) {};
    virtual void update(Circuit&, MNAEquation&, real_t) {};

    Component(const Component&) = delete;
    Component& operator=(const Component&) = delete;
};