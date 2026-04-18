#include <simulation/simulation.hpp>

Simulation::Simulation() :

circuit(std::make_unique<Circuit>())
{
}

void Simulation::connect(const Terminal& p_t1, const Terminal& p_t2) {
    circuit->connect(p_t1, p_t2);
}

void Simulation::build() {
    equation = std::make_unique<MNAEquation>(circuit->get_node_count());
    circuit->build(*equation);
}

void Simulation::simulate()
{
    VectorX x = equation->solve();

    int n = equation->get_node_count();
    int m = equation->get_voltage_source_count();

    for (int i=0; i<n; i++) {
        std::cout << "Node " << i << " voltage: " << x[i] << "V\n";
    }
    for (int i=0; i<m; i++) {
        std::cout << "Source " << i << " current: " << x[i+n] << "A\n";
    }
}
