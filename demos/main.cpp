#include<iostream>
#include<global.hpp>

#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>
#include<comps/voltmeter.hpp>
#include<comps/ammeter.hpp>

void voltage_divider_demo() {
    std::cout << "# Running: Voltage Divider Demo\n";
    Simulation sim;

    double Vsource = 10;

    Resistor& r1 = sim.add<Resistor>(20);
    Resistor& r2 = sim.add<Resistor>(20);
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

    double V = 10.0;
    double R = 5.0;

    DCPower& v1 = sim.add<DCPower>(V);
    Resistor& r1 = sim.add<Resistor>(R);
    Ammeter& am = sim.add<Ammeter>();

    // v1 -- r1 -- am

    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, am.Plus);

    sim.build();
    sim.step();

    // I = V / R
    std::cout << "V = " << V << "V,  R = " << R << "Ω,  I = " << am.measure() << "A\n\n";
}

int main() {

    std::cout << "===================\nSTARTING\n===================\n";
    
    voltage_divider_demo();
    ohms_law_demo();
    
}
