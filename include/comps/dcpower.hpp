#pragma once

#include<global.hpp>
#include<comps/component.hpp>

class DCPower : public Component {
    protected:
    real_t voltage;
    int voltage_source_id;

    public:
    const Terminal& Plus = terminals[0];
    const Terminal& Minus = terminals[1];

    DCPower(ComponentID p_id, real_t p_voltage);
    void build(Circuit& p_circuit, MNAEquation& p_equation) override;
};