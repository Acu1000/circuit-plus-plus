#pragma once

#include<global.hpp>
#include<comps/component.hpp>
#include<functional>

class ACPower : public Component {
    protected:
    real_t t_elapsed;
    std::function<real_t(real_t)> func;
    int voltage_source_id;

    public:
    const Terminal& Plus = terminals[0];
    const Terminal& Minus = terminals[1];

    ACPower(ComponentID p_id);
    void set_sine_wave(real_t p_amplitude, real_t p_frequency, real_t p_shift=0);
    void build(Circuit& p_circuit, MNAEquation& p_equation) override;
    void update(Circuit& p_circuit, MNAEquation& p_equation, real_t dt) override;
};