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
        bool is_built = false;

        real_t dt = 5e-6;

        long elapsed_steps = 0;

    public:
        Simulation();

        template<typename TComponent, typename... Args>
        TComponent& add(Args&&... args) { 
            if (is_built) throw std::runtime_error("Attempted to modify circuit post-build");
            
            return circuit->add<TComponent>(std::forward<Args>(args)...); 
        }
        void connect(const Terminal& p_t1, const Terminal& p_t2);

        void set_timestep(real_t p_dt);
        void build();

        void step();
        void run_for_steps(int p_steps);
        void run_for_time(real_t p_time);
};