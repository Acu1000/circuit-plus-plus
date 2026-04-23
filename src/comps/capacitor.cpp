#include<comps/capacitor.hpp>
#include<simulation/circuit.hpp>
#include<simulation/mna_equation.hpp>

Capacitor::Capacitor(ComponentID p_id, real_t p_capacitance, real_t p_init_voltage) 
    : Component(p_id, 2), 
    capacitance(p_capacitance),
    prev_voltage(p_init_voltage)
{
}

void Capacitor::build(ComponentBuildDto dto)
{
    // Stamp conductance
    real_t conductance = capacitance / dto.dt;
    if (dto.circuit.is_terminal_connected(A.get_id())) {
        NodeID node_a_id = dto.circuit.get_terminal_node(A.get_id());
        dto.equation.add_static_conductance(node_a_id, node_a_id, conductance);
    }
    if (dto.circuit.is_terminal_connected(B.get_id())) {
        NodeID node_b_id = dto.circuit.get_terminal_node(B.get_id());
        dto.equation.add_static_conductance(node_b_id, node_b_id, conductance);
    }
    if (dto.circuit.is_terminal_connected(A.get_id()) && dto.circuit.is_terminal_connected(B.get_id())) {
        NodeID node_a_id = dto.circuit.get_terminal_node(A.get_id());
        NodeID node_b_id = dto.circuit.get_terminal_node(B.get_id());
        dto.equation.add_static_conductance(node_a_id, node_b_id, -conductance);
        dto.equation.add_static_conductance(node_b_id, node_a_id, -conductance);
    }
}

// TODO: optimize the whole thing, possibly move update logic to an SoA
void Capacitor::update(ComponentUpdateDto dto)
{
    // Get current voltage
    real_t a_voltage = 0;
    real_t b_voltage = 0;
    TerminalID a_terminal_id = A.get_id();
    if (dto.circuit.is_terminal_connected(a_terminal_id)) {
        int a_node_id = dto.circuit.get_terminal_node(a_terminal_id);
        a_voltage = dto.equation.get_node_voltage(a_node_id);
    }
    TerminalID b_terminal_id = B.get_id();
    if (dto.circuit.is_terminal_connected(b_terminal_id)) {
        int b_node_id = dto.circuit.get_terminal_node(b_terminal_id);
        b_voltage = dto.equation.get_node_voltage(b_node_id);
    }
    real_t cur_voltage = a_voltage - b_voltage;
    //std::cout << "C volt: " << cur_voltage << '\n';

    // Stamp injected current
    real_t conductance = capacitance / dto.dt;
    real_t current = conductance * prev_voltage;   // TODO: consider other differentiation methods

    //std::cout << "C cur: " << current << '\n';

    if (dto.circuit.is_terminal_connected(a_terminal_id)) {
        int a_node_id = dto.circuit.get_terminal_node(a_terminal_id);
        dto.equation.add_dynamic_current(a_node_id, current);
    }
    if (dto.circuit.is_terminal_connected(b_terminal_id)) {
        int b_node_id = dto.circuit.get_terminal_node(b_terminal_id);
        dto.equation.add_dynamic_current(b_node_id, -current);
    }

    // Save current voltage for next step
    prev_voltage = cur_voltage;
}
