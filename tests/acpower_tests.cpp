#include<gtest/gtest.h>

#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/capacitor.hpp>
#include<comps/voltmeter.hpp>
#include<comps/acpower.hpp>

TEST(ACPowerTests, SineWaveHasCorrectZerosAndAmplitudes) {
    Simulation sim;

    // TODO: Test for multiple parameters
    double amplitude = 10;
    double frequency = 10;
    double shift = 0;

    double period = (1.0 / frequency);

    auto& v1 = sim.add<ACPower>();
    auto& out_v = sim.add<Voltmeter>();

    sim.connect(v1.Plus, out_v.Plus);

    v1.set_sine_wave(amplitude, frequency, shift);

    sim.set_timestep(1e-5);
    sim.build();

    for(int i=0; i<5; i++) {
        EXPECT_NEAR(out_v.measure(), 0, 1e-2); // TODO: consider possibility of achieving better precision
        EXPECT_NEAR(v1.get_voltage(), 0, 1e-2);
        sim.run_for_time(period/4);
        EXPECT_NEAR(out_v.measure(), amplitude, 1e-5);
        EXPECT_NEAR(v1.get_voltage(), amplitude, 1e-5);
        sim.run_for_time(period/4);
        EXPECT_NEAR(out_v.measure(), 0, 1e-2);
        EXPECT_NEAR(v1.get_voltage(), 0, 1e-2);
        sim.run_for_time(period/4);
        EXPECT_NEAR(out_v.measure(), -amplitude, 1e-5);
        EXPECT_NEAR(v1.get_voltage(), -amplitude, 1e-5);
        sim.run_for_time(period/4);
    }
}