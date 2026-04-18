#pragma once

#include<global.hpp>
#include<comps/component.hpp>

class Voltmeter : public Component {
    private:
        real_t last_voltage = 0;

    public:
        const Terminal& Plus = terminals[0];
        const Terminal& Minus = terminals[1];

        Voltmeter(ComponentID p_id);
        real_t measure();

        void update(Circuit& p_circuit, MNAEquation& p_equation) override;
};