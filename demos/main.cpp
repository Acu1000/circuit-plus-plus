#include<iostream>
#include<global.hpp>

#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>
#include<comps/voltmeter.hpp>

int main() {

    std::cout << "===================\nSTARTING\n===================\n";
    
    Simulation sim;

    Resistor& r1 = sim.add<Resistor>(10);
    Resistor& r2 = sim.add<Resistor>(20);
    Resistor& r3 = sim.add<Resistor>(40);
    DCPower& v1 = sim.add<DCPower>(10);
    Voltmeter& vm = sim.add<Voltmeter>(); 

    //     ,-vm-,
    // v1 -- r1 -- r2
    //          |
    //          r3

    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, r2.A);
    sim.connect(r1.B, r3.A);
    sim.connect(vm.Plus, r1.A);
    sim.connect(vm.Minus, r1.B);

    sim.build();

    sim.step();

    std::cout << "Voltage at r1: " << vm.measure() << "V\n";
}
