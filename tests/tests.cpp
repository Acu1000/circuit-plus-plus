#include<gtest/gtest.h>

#include<simulation/simulation.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>
#include<comps/voltmeter.hpp>

TEST(BasicTest, VoltageDivisionTest) {
    Simulation sim;

    DCPower& v1 = sim.add<DCPower>(10);
    Resistor& r1 = sim.add<Resistor>(20);
    Resistor& r2 = sim.add<Resistor>(20);
    Voltmeter& vm = sim.add<Voltmeter>();

    sim.connect(v1.Plus, r1.A);
    sim.connect(r1.B, r2.A);
    sim.connect(vm.Plus, r1.A);
    sim.connect(vm.Minus, r1.B);

    sim.build();

    sim.step();

    double voltage = vm.measure();
    EXPECT_NEAR(voltage, 5.0, 0.001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}