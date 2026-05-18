#pragma once

#include<global.hpp>
#include<vector>
#include<unordered_set>
#include<parts/terminal.hpp>

class Node {
    private:
    std::unordered_set<TerminalID> terminals;
    NodeID id;

    public:
    Node(int p_id);

    int get_id() {return id;}
    void add_terminal(TerminalID p_terminal);
    bool has_terminal(TerminalID p_terminal);
    void remove_terminal(TerminalID p_terminal);
};