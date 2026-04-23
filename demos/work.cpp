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

int main() {

    std::cout << "===================\nSTARTING\n===================\n";
    //voltage_divider_demo();
    //ohms_law_demo();

    // Low Pass RC Filter
    Simulation sim;

    auto& v1 = sim.add<ACPower>();
    auto& r1 = sim.add<Resistor>(200);
    auto& c1 = sim.add<Capacitor>(1e-5);
    auto& out_v = sim.add<Voltmeter>();

    v1.set_sine_wave(100, 200);

    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, out_v.Plus);
    sim.connect(r1.B, c1.A);

    sim.set_timestep(5e-6);
    sim.build();

    double max_v = 0;
    for (int i=0; i<10000; i++) {
        sim.step();
        max_v = std::max(max_v, out_v.measure());
    }

    std::cout << "Max voltage: " << max_v << "V\n";

    return 0;
}
