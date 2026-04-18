#pragma once

#include<global.hpp>
#include<comps/component.hpp>

class DCPower : public Component {
    private:
    real_t voltage;

    public:
    const Terminal& Plus = terminals[0];
    const Terminal& Minus = terminals[1];

    DCPower(ComponentID p_id, real_t p_voltage);
    void build(Circuit& builder, MNAEquation& sim) override;
};