#pragma once

#include<iostream>
#include<optional>
#include<functional>
#include<vector>

using namespace std;

typedef double real_t;

typedef int ComponentID;
typedef int TerminalSubID;
typedef int NodeID;

typedef pair<const ComponentID, const TerminalSubID> TerminalID;

template<>
struct std::hash<TerminalID>{
    size_t operator()(const TerminalID& p) const {
        auto left = std::hash<ComponentID>{}(p.first);
        auto right = std::hash<TerminalSubID>{}(p.second);

        return left ^ (right << 1);
    }
};

template<typename T>
using NullableRef = std::optional<std::reference_wrapper<T>>;
