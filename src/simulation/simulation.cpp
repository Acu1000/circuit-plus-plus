#include <simulation/simulation.hpp>
#include <dto/component_update_dto.hpp>

Simulation::Simulation() :
circuit(std::make_unique<Circuit>())
{
}

void Simulation::connect(const Terminal& p_t1, const Terminal& p_t2) {
    if (is_built) throw std::logic_error("Attempted to modify circuit post-build");
    circuit->connect(p_t1, p_t2);
}

void Simulation::set_timestep(real_t p_dt) {
    if (is_built) throw std::logic_error("Timestep currently can only be set before build"); // TODO: support dynamic timestep
    dt = p_dt;
}

void Simulation::build() {
    if (is_built) throw std::logic_error("Attempted to build same simulation twice");
    equation = std::make_unique<MNAEquation>(circuit->get_node_count());
    for (auto& comp : circuit->get_components()) {
        comp->build({*circuit, *equation, dt});
    }
    is_built = true;
}

void Simulation::step()
{
    if (!is_built) throw std::logic_error("Attempted to run unbuilt simulation");
    
    VectorX x = equation->solve();

    for (auto& comp : circuit->get_components()) {
        comp->update({*circuit, *equation, dt, elapsed_steps});
    }
    
    elapsed_steps++;

    /*
    int n = equation->get_node_count();
    int m = equation->get_voltage_source_count();

    for (int i=0; i<n; i++) {
        std::cout << "Node " << i << " voltage: " << x[i] << "V\n";
    }
    for (int i=0; i<m; i++) {
        std::cout << "Source " << i << " current: " << x[i+n] << "A\n";
    }
    */
    
}

void Simulation::run_for_steps(int p_steps)
{
    if (!is_built) throw std::logic_error("Attempted to run unbuilt simulation");
    for (int i=0; i<p_steps; i++) {
        step();
    }
}

void Simulation::run_for_time(real_t p_time)
{
    if (!is_built) throw std::logic_error("Attempted to run unbuilt simulation");
    int steps = static_cast<int>(p_time / dt);
    run_for_steps(steps);
}
