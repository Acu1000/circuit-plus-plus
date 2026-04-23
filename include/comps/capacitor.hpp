#pragma once

#include<global.hpp>
#include<comps/component.hpp>

class Capacitor : public Component {
    private:
        real_t capacitance;
        real_t prev_voltage = 0;

    public:
        const Terminal& A = terminals[0];
        const Terminal& B = terminals[1];

        Capacitor(ComponentID p_id, real_t p_capacitance, real_t p_init_voltage=0);

        void build(ComponentBuildDto dto) override;
        void update(ComponentUpdateDto dto) override;
};