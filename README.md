# Circuit++ Circuit Simulator (WIP)
This is a simple c++ library to simulate low-level electronic circuits. Currently it supports DC powered circuits with resistors. Transient simulation and dynamic elements are currently being worked on

Building circuits is done in code and results are printed to the console

The project is currently work in progress

# Example code
The following code uses the library to demonstrate [Ohm's law](https://en.wikipedia.org/wiki/Ohm%27s_law) 
by creating a simple circuit with a DC voltage source, resistor and ammeter.
```cpp
std::cout << "# Running: Ohm's Law Demo\n";
Simulation sim;

double V = 10_V;  // Voltage
double R = 5_Ohm;   // Resistance

DCPower& v1 = sim.add<DCPower>(V);    // Add DC voltage source v1
Resistor& r1 = sim.add<Resistor>(R);  // Add resistor r1
Ammeter& A1 = sim.add<Ammeter>();     // Add ammeter A1

// v1 -- r1 -- A1

// Connect the 3 components in series
sim.connect(v1.Plus, r1.A);  // Connect v1 to r1
sim.connect(r1.B, A1.Plus);  // Connect r1 to A1

sim.build();  // Build the simulation
sim.step();   // Run the simulation for a single time step

// We read the current from A1 and realize that I = V / R
std::cout << "V = " << V << "V,  R = " << R << "Ω,  I = " << A1.measure() << "A\n\n";
```
Output:
```
# Running: Ohm's Law Demo
V = 10V,  R = 5Ω,  I = 2A
```
# Compiling
> [!WARNING]
> The below instructions are for Linux. Functionality of the project on Windows & MacOS is not yet known. Feel free to give it a try though and let me know what happened.

Before compilation ensure you have installed the [Eigen](https://libeigen.gitlab.io/) library on your system.

This project uses the [Meson](https://mesonbuild.com/) build system. In order to build the project, ensure you have Meson installed and run the following commands in the project directory:
```
meson setup build
meson compile -C build
```
The compiled library, tests and demo executables will appear in the `build` directory.
