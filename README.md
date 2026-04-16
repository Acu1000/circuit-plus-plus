# C++ Circuit Simulator (WIP)
This is a simple c++ library to simulate low-level electronic circuits. Currently it supports DC powered circuits with resistors. 
Building circuits is done in code and results are printed to the console.

The project is currently work in progress.

# Example code
```cpp
SimulationBuilder& builder = *SimulationBuilder::get();

Resistor& r1 = builder.add<Resistor>(10);
Resistor& r2 = builder.add<Resistor>(20);
Resistor& r3 = builder.add<Resistor>(40);
DCPower& v1 = builder.add<DCPower>(10);

// v1 -- r1 -- r2
//          |
//          r3

builder.connect(v1.Plus, r1.A);
builder.connect(r1.B, r2.A);
builder.connect(r1.B, r3.A);

Simulation sim = builder.build();

sim.simulate();
```
