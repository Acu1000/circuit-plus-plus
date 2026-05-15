#pragma once

#include<global.hpp>
#include<comps/component.hpp>
#include<functional>

class ACPower : public Component {
    protected:
    std::function<real_t(real_t)> func;
    int voltage_source_id;

    real_t last_voltage=0;

    public:
    const Terminal& Plus = terminals[0];
    const Terminal& Minus = terminals[1];

    ACPower(ComponentID p_id);
    ACPower& set_sine_wave(real_t p_amplitude, real_t p_frequency, real_t p_shift=0);
    void build(ComponentBuildDto dto) override;
    void update(ComponentUpdateDto dto) override;

    real_t get_voltage();
};