#include<gtest/gtest.h>

#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>
#include<comps/ammeter.hpp>
#include<comps/voltmeter.hpp>

TEST(ResistorTests, DoesNotThrowWhenTerminalsAreDisconnected) {
    Simulation sim;

    [[maybe_unused]] Resistor& ab_disconnected_resistor = sim.add<Resistor>(10);
    Resistor& a_disconnected_resistor = sim.add<Resistor>(10);
    Resistor& b_disconnected_resistor = sim.add<Resistor>(10);

    sim.connect(a_disconnected_resistor.B, b_disconnected_resistor.A);

    ASSERT_NO_THROW(sim.build());
    ASSERT_NO_THROW(sim.step());
}

TEST(ResistorTests, FollowsOhmsLaw) {
    Simulation sim;

    double voltage = 10.0;
    double resistance = 5.0;

    DCPower& v1 = sim.add<DCPower>(10);
    Resistor& r1 = sim.add<Resistor>(5);
    Ammeter& A1 = sim.add<Ammeter>();

    // v1 -- r1 -- A1
    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, A1.Plus);

    sim.build();
    sim.step();

    EXPECT_NEAR(A1.measure(), voltage/resistance, 0.0001);
}

TEST(ResistorTests, SimpleVoltageDividerWorksProperly) {
    Simulation sim;

    double source_voltage = 10.0;
    double resistance1 = 20.0;      // TODO: test for different values
    double resistance2 = 20.0;

    DCPower& v1 = sim.add<DCPower>(source_voltage);
    Resistor& r1 = sim.add<Resistor>(resistance1);
    Resistor& r2 = sim.add<Resistor>(resistance2);
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

    EXPECT_NEAR(V1.measure(), source_voltage * resistance1/(resistance1+resistance2), 0.0001);
    EXPECT_NEAR(V2.measure(), source_voltage * resistance2/(resistance1+resistance2), 0.0001);
}