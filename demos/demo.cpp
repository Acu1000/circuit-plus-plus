#include<iostream>
#include<global.hpp>

#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/capacitor.hpp>
#include<comps/dcpower.hpp>
#include<comps/voltmeter.hpp>
#include<comps/ammeter.hpp>
#include<comps/acpower.hpp>

#include<util/units.hpp>

void voltage_divider_demo() {
    std::cout << "# Running: Voltage Divider Demo\n";
    Simulation sim;

    double Vsource = 10_V;

    Resistor& r1 = sim.add<Resistor>(20_Ohm);
    Resistor& r2 = sim.add<Resistor>(20_Ohm);
    DCPower& v1 = sim.add<DCPower>(Vsource);
    Voltmeter& V1 = sim.add<Voltmeter>();
    Voltmeter& V2 = sim.add<Voltmeter>(); 

    //     ,-V1-, ,-V2
    // v1 -- r1 -- r2

    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, r2.A);
    sim.connect(V1.Plus, r1.A);
    sim.connect(V1.Minus, r1.B);
    sim.connect(V2.Plus, r2.A);

    sim.build();

    sim.step();

    std::cout << "Vsource = " << Vsource << "V,  V1 = " << V1.measure() << "V,  V2 = " << V2.measure() << "V\n\n";
}

void ohms_law_demo() {
    std::cout << "# Running: Ohm's Law Demo\n";
    Simulation sim;

    double V = 10_V;  // Voltage
    double R = 5_Ohm;   // Resistance

    DCPower& v1 = sim.add<DCPower>(V);    // Add DC voltage source v1
    Resistor& r1 = sim.add<Resistor>(R);  // Add resistor r1
    Ammeter& A1 = sim.add<Ammeter>();     // Add ammeter A1

    // v1 -- r1 -- A1

    // Connect the 3 components in series
    sim.connect(v1.Plus, r1.A);  // Connect v1 to r1
    sim.connect(r1.B, A1.Plus);  // Connect r1 to A1

    sim.build();  // Build the simulation
    sim.step();   // Run the simulation for a single time step

    // I = V / R
    std::cout << "V = " << V << "V,  R = " << R << "Ω,  I = " << A1.measure() << "A\n\n";
}

int main() {

    voltage_divider_demo();
    ohms_law_demo();

    return 0;
}