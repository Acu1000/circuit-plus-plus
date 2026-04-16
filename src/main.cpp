#include<iostream>
#include<global.hpp>

#include<simulation/simulation_builder.hpp>
#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>

int main() {

    cout << "===================\nSTARTING\n===================\n";
    
    SimulationBuilder& builder = *SimulationBuilder::get();

    Resistor r1(10);
    builder.add_component(r1);
    Resistor r2(20);
    builder.add_component(r2);
    Resistor r3(40);
    builder.add_component(r3);
    DCPower v1(10);
    builder.add_component(v1);

    // v1 -- r1 -- r2
    //          |
    //          r3

    v1.Plus.connect(r1.A);
    r1.B.connect(r2.A);
    r1.B.connect(r3.A);

    Simulation sim = builder.build();

    sim.simulate();
}
