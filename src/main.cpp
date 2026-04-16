#include<iostream>
#include<global.hpp>

#include<simulation/simulation_builder.hpp>
#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>

int main() {

    cout << "===================\nSTARTING\n===================\n";
    
    SimulationBuilder& builder = *SimulationBuilder::get();

    Resistor& r1 = builder.add<Resistor>(10);
    Resistor& r2 = builder.add<Resistor>(20);
    Resistor& r3 = builder.add<Resistor>(40);
    DCPower& v1 = builder.add<DCPower>(10);

    // v1 -- r1 -- r2
    //          |
    //          r3

    v1.Plus.connect(r1.A);
    r1.B.connect(r2.A);
    r1.B.connect(r3.A);

    Simulation sim = builder.build();

    sim.simulate();
}
