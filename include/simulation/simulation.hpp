#pragma once

#include<global.hpp>
#include<Eigen/Dense>
#include<memory>
#include<simulation/circuit.hpp>
#include<simulation/mna_equation.hpp>

class Simulation {

    private:
        std::unique_ptr<Circuit> circuit;
        std::unique_ptr<MNAEquation> equation;

    public:
        Simulation();

        template<typename TComponent, typename... Args>
        TComponent& add(Args&&... args) { return circuit->add<TComponent>(std::forward<Args>(args)...); }
        void connect(const Terminal& p_t1, const Terminal& p_t2);

        void build();

        void simulate();
};