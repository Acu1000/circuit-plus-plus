#include<simulation/simulation_builder.hpp>
#include<simulation/simulation.hpp>

SimulationBuilder* SimulationBuilder::instance = nullptr;

Node& SimulationBuilder::create_node()
{
    Node new_node(nodes.size());
    nodes.push_back(new_node);
    return nodes.back();
}

Simulation SimulationBuilder::build() {
    Simulation sim(nodes.size());

    for (const auto& comp : components) {
        comp->build(sim);
    }

    return sim;
}