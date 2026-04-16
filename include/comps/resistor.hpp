#pragma once

#include<global.hpp>
#include<comps/component.hpp>

class Resistor : public Component {
    public:
    const Terminal& A = terminals[0];
    const Terminal& B = terminals[1];

    Resistor(ComponentID p_id, real_t p_resistance);

    void build(SimulationBuilder& builder, Simulation& sim) override;

    private:
    real_t resistance;

};