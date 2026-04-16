#include<comps/dcpower.hpp>
#include<simulation/simulation.hpp>
#include<simulation/simulation_builder.hpp>

DCPower::DCPower(ComponentID p_id, real_t p_voltage) : Component(p_id), voltage(p_voltage) {}

void DCPower::build(SimulationBuilder& builder, Simulation &sim)
{
    if (builder.is_terminal_connected(Plus.get_id()) || builder.is_terminal_connected(Minus.get_id())) {
        int id = sim.add_voltage_source();
        sim.set_source_voltage(id, voltage); // TODO: might have to make this dynamic instead

        if (builder.is_terminal_connected(Plus.get_id())) {
            sim.set_connection(builder.get_terminal_node(Plus.get_id()), id, +1);
        }

        if (builder.is_terminal_connected(Minus.get_id())) {
            sim.set_connection(builder.get_terminal_node(Minus.get_id()), id, -1);
        }
    }
}