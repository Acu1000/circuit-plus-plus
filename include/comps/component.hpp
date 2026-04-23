#pragma once

#include<global.hpp>
#include<parts/terminal.hpp>
#include<dto/component_build_dto.hpp>
#include<dto/component_update_dto.hpp>
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
    virtual void build(ComponentBuildDto) {};
    virtual void update(ComponentUpdateDto) {};

    Component(const Component&) = delete;
    Component& operator=(const Component&) = delete;
};