#include<global.hpp>
#include<Eigen/Dense>

typedef Eigen::Matrix<real_t, Eigen::Dynamic, Eigen::Dynamic> MatrixX;
typedef Eigen::Vector<real_t, Eigen::Dynamic> VectorX;
typedef Eigen::Block<real_t, Eigen::Dynamic, Eigen::Dynamic> BlockX;

class MNAEquation {
    private:
        int node_count=0;
        int voltage_source_count=0;
        
        // Conductance matrix components
        MatrixX static_G, dynamic_G;
        // Connection matrices
        MatrixX B, C; 
        // Dependent source matrix
        MatrixX D;
        // Injected current vector components
        VectorX static_I, dynamic_I;
        // Source voltage vector
        VectorX E;

        // Equation solution
        VectorX solution;

        Eigen::ColPivHouseholderQR<MatrixX> decomp;
        bool decomp_update_needed = true;

    public:
        MNAEquation(int p_node_count);

        int get_node_count();
        int get_voltage_source_count();

        void add_static_conductance(int p_node_id1, int p_node_id2, real_t p_conductance);
        void add_dynamic_conductance(int p_node_id1, int p_node_id2, real_t p_conductance);
        void add_dynamic_current(int p_node_id, real_t p_current);

        int add_voltage_source();
        void set_connection(int p_node_id, int p_source_id, int p_value);
        void set_source_voltage(int p_source_id, real_t p_voltage);

        VectorX solve();
        VectorX get_last_solution();
        real_t get_node_voltage(int p_node_id);
        real_t get_voltage_source_current(int p_source_id);
};