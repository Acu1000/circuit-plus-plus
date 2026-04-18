# C++ Circuit Simulator (WIP)
This is a simple c++ library to simulate low-level electronic circuits. Currently it supports DC powered circuits with resistors. 
Building circuits is done in code and results are printed to the console.

The project is currently work in progress.

# Example code
```cpp
Simulation sim;

Resistor& r1 = sim.add<Resistor>(10);
Resistor& r2 = sim.add<Resistor>(20);
Resistor& r3 = sim.add<Resistor>(40);
DCPower& v1 = sim.add<DCPower>(10);

// v1 -- r1 -- r2
//          |
//          r3

sim.connect(v1.Plus, r1.A);
sim.connect(r1.B, r2.A);
sim.connect(r1.B, r3.A);

sim.build();

sim.simulate();
```
