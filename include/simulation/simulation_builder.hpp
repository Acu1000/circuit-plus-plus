#pragma once

#include<global.hpp>
#include<vector>
#include<memory>
#include<unordered_map>
#include<parts/node.hpp>
#include<comps/component.hpp>

// Singleton
class SimulationBuilder {
    private:
    std::vector<Node> nodes;
    std::vector<std::unique_ptr<Component>> components;
    std::unordered_map<TerminalID, NodeID> terminal_connections;
    NodeID create_node();
    
    public:
    SimulationBuilder();
    Simulation build();
    
    template<typename TComponent, typename... Args>
    TComponent& add(Args&&... args) {
        ComponentID id = components.size();
        std::unique_ptr<TComponent> ptr = std::make_unique<TComponent>(id, std::forward<Args>(args)...);
        TComponent& ref = *ptr;
        components.push_back(std::move(ptr));
        return ref;
    }
    
    void connect(Terminal p_t1, Terminal p_t2);
    
    bool is_terminal_connected(TerminalID p_terminal);
    NodeID get_terminal_node(TerminalID p_terminal);
    void set_terminal_node(TerminalID p_terminal, NodeID p_node);
};