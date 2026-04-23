#include<gtest/gtest.h>

#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/capacitor.hpp>
#include<comps/dcpower.hpp>
#include<comps/ammeter.hpp>
#include<comps/voltmeter.hpp>
#include<comps/acpower.hpp>

TEST(CapacitorTests, DoesNotThrowWhenTerminalsAreDisconnected) {
    Simulation sim;

    [[maybe_unused]] Capacitor& ab_disconnected_capacitor = sim.add<Capacitor>(10);
    Capacitor& a_disconnected_capacitor = sim.add<Capacitor>(10);
    Capacitor& b_disconnected_capacitor = sim.add<Capacitor>(10);

    sim.connect(a_disconnected_capacitor.B, b_disconnected_capacitor.A);

    ASSERT_NO_THROW(sim.build());
    ASSERT_NO_THROW(sim.step());
}

TEST(CapacitorTests, BlocksDCCurrent) {
    Simulation sim;

    double voltage = 10;

    auto& v1 = sim.add<DCPower>(voltage);
    auto& r1 = sim.add<Resistor>(10);
    auto& c1 = sim.add<Capacitor>(1e-5);
    auto& A1 = sim.add<Ammeter>();
    auto& V1 = sim.add<Voltmeter>();

    //v1.set_sine_wave(100, 60);

    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, c1.A);
    sim.connect(c1.B, A1.Plus);

    sim.connect(V1.Plus, c1.A);
    sim.connect(V1.Minus, c1.B);

    sim.set_timestep(1e-6);
    sim.build();

    sim.run_for_steps(10000);

    EXPECT_NEAR(A1.measure(), 0, 1e-6);
    EXPECT_NEAR(V1.measure(), voltage, 1e-6);
}

TEST(CapacitorTests, LowPassRCFilterAllowsLowFrequencies) {
    Simulation sim;

    auto& v1 = sim.add<ACPower>();
    auto& r1 = sim.add<Resistor>(200);
    auto& c1 = sim.add<Capacitor>(1e-5);
    auto& out_v = sim.add<Voltmeter>();

    v1.set_sine_wave(100, 5);

    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, out_v.Plus);
    sim.connect(r1.B, c1.A);

    sim.set_timestep(5e-6);
    sim.build();

    double max_v = 0;
    for (int i=0; i<50000; i++) {
        sim.step();
        max_v = std::max(max_v, out_v.measure());
    }

    EXPECT_GT(max_v, 90); // TODO: figure out how to get more accurate results
}

// TODO: make shared setup with the other low pass filter test
TEST(CapacitorTests, LowPassRCFilterAttenuatesHighFrequencies) {
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
    for (int i=0; i<2000; i++) {
        sim.step();
        max_v = std::max(max_v, out_v.measure());
    }

    EXPECT_LT(max_v, 40); // TODO: figure out how to get more accurate results
}

// TODO: Tests for sudden voltage changes
/*TEST(CapacitorTest, DischargesAtCorrectSpeedWithInitialVoltageAndNoPowerSource) {

}*/

// TODO: Low and high-pass RC filter tests