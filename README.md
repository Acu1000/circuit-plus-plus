# C++ Circuit Simulator (WIP)
This is a simple c++ library to simulate low-level electronic circuits. Currently it supports DC powered circuits with resistors. 
Building circuits is done in code and results are printed to the console.

The project is currently work in progress.

# Example code
```cpp
SimulationBuilder& builder = *SimulationBuilder::get();

Resistor r1(10);
builder.add_component(r1);
Resistor r2(20);
builder.add_component(r2);
Resistor r3(40);
builder.add_component(r3);
DCPower v1(10);
builder.add_component(v1);

// v1 -- r1 -- r2
//          |
//          r3

v1.Plus.connect(r1.A);
r1.B.connect(r2.A);
r1.B.connect(r3.A);

Simulation sim = builder.build();

sim.simulate();
```
