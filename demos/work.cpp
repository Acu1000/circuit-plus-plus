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

    auto& v1 = sim.add<ACPower>().set_sine_wave(100_V, 200_Hz);
    auto& r1 = sim.add<Resistor>(200_Ohm);
    auto& c1 = sim.add<Capacitor>(10_uF);
    auto& out_v = sim.add<Voltmeter>();

    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, out_v.Plus);
    sim.connect(r1.B, c1.A);

    sim.set_timestep(5_us);
    sim.build();

    sim.run_for_time(5.0/200.0 + 1.0/800.0);
    sim._dump_equation();

    double max_v = 0;
    for (int i=0; i<10000; i++) {
        sim.step();
        max_v = std::max(max_v, out_v.measure());
    }

    std::cout << "Max voltage: " << max_v << "V\n";

    return 0;
}
