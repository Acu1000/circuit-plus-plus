#include<simulation/mna_equation.hpp>

MNAEquation::MNAEquation(int p_node_count) :
    node_count(p_node_count),
    static_G(MatrixX::Zero(p_node_count, p_node_count)),
    dynamic_G(MatrixX::Zero(p_node_count, p_node_count)),
    B(MatrixX::Zero(p_node_count, 0)),
    C(MatrixX::Zero(0, p_node_count)),
    D(MatrixX::Zero(0, 0)),
    static_I(VectorX::Zero(p_node_count)),
    dynamic_I(VectorX::Zero(p_node_count)),
    E(VectorX::Zero(0)),
    solution(VectorX::Zero(p_node_count))
{
}

int MNAEquation::get_node_count() { return node_count; }
int MNAEquation::get_voltage_source_count() { return voltage_source_count; }

void MNAEquation::add_static_conductance(int p_node_id1, int p_node_id2, real_t p_conductance)
{
    static_G(p_node_id1, p_node_id2) += p_conductance;
}

void MNAEquation::add_dynamic_conductance(int p_node_id1, int p_node_id2, real_t p_conductance)
{
    decomp_update_needed = true;
    dynamic_G(p_node_id1, p_node_id2) += p_conductance;
}

int MNAEquation::add_voltage_source()
{
    voltage_source_count++;

    B.conservativeResize(node_count, voltage_source_count);
    C.conservativeResize(voltage_source_count, node_count);
    for (int i=0; i<node_count; i++) {
        B(i, voltage_source_count-1) = 0;
        C(voltage_source_count-1, i) = 0;
    }

    D.conservativeResize(voltage_source_count, voltage_source_count);
    for (int i=0; i<voltage_source_count; i++) {
        D(voltage_source_count-1, i) = 0;
        D(i, voltage_source_count-1) = 0;
    }

    E.conservativeResize(voltage_source_count);
    E(voltage_source_count-1) = 0;

    solution.conservativeResize(node_count + voltage_source_count);

    return voltage_source_count-1;
}

void MNAEquation::add_dynamic_current(int p_node_id, real_t p_current) {
    dynamic_I[p_node_id] += p_current;
}


void MNAEquation::set_connection(int p_node_id, int p_source_id, int p_value)
{   
    B(p_node_id, p_source_id) = p_value;
    C(p_source_id, p_node_id) = p_value;
}

void MNAEquation::set_source_voltage(int p_source_id, real_t p_voltage)
{
    E(p_source_id) = p_voltage;
}

VectorX MNAEquation::solve()
{
    // |G B| |v|   |I|
    // |C D| |i| = |E|

    MatrixX G = static_G + dynamic_G;
    VectorX I = static_I + dynamic_I;

    MatrixX GBCD;
    GBCD.resize(node_count+voltage_source_count, node_count+voltage_source_count);
    GBCD.block(0, 0, node_count, node_count) = G;
    GBCD.block(0, node_count, node_count, voltage_source_count) = B;
    GBCD.block(node_count, 0, voltage_source_count, node_count) = C;
    GBCD.block(node_count, node_count, voltage_source_count, voltage_source_count) = D;

    VectorX IE(node_count+voltage_source_count);
    IE.block(0, 0, node_count, 1) = I;
    IE.block(node_count, 0, voltage_source_count, 1) = E;

    if (abs(GBCD.determinant()) < 0.001) {
        throw std::logic_error("Unsimulable circuit (MNA matrix determinant is 0)");
    }

    if (decomp_update_needed) {
        decomp = GBCD.colPivHouseholderQr();
        decomp_update_needed = false;
    }
    solution = decomp.solve(IE);

    dynamic_G.setZero();
    dynamic_I.setZero();

    return solution;
}

real_t MNAEquation::get_node_voltage(int p_node_id)
{
    return solution[p_node_id];
}

real_t MNAEquation::get_voltage_source_current(int p_source_id)
{
    return solution[node_count + p_source_id];
}