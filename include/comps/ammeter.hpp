#pragma once

#include<global.hpp>
#include<comps/component.hpp>
#include<comps/dcpower.hpp>

class Ammeter : public DCPower {
    private:
        real_t last_current = 0;

    public:
        const Terminal& Plus = terminals[0];
        const Terminal& Minus = terminals[1];
        Ammeter(ComponentID p_id);
        void update(ComponentUpdateDto dto) override;
        real_t measure();
};
