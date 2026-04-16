#pragma once

#include<global.hpp>
#include<vector>
#include<memory>
#include<parts/node.hpp>
#include<comps/component.hpp>

// Singleton
class SimulationBuilder {
    protected:
    static SimulationBuilder* instance;
    SimulationBuilder() {}

    public:
    static SimulationBuilder* get() {
        if (instance == nullptr) {
            instance = new SimulationBuilder();
        }
        return instance;
    }

    // prevent cloning and assigning
    SimulationBuilder(SimulationBuilder& other) = delete;
    void operator=(const SimulationBuilder &) = delete;

    private:
    vector<Node> nodes;
    vector<unique_ptr<Component>> components;

    public:
    Node& create_node();
    Simulation build();

    template<typename T, typename... Args>
    T& add(Args&&... args) {
        unique_ptr<T> ptr = make_unique<T>(forward<Args>(args)...);
        T& ref = *ptr;
        components.push_back(move(ptr));
        return ref;
    }

};