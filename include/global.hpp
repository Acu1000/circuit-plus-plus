#pragma once

#include<iostream>
#include<optional>
#include<functional>
#include<vector>

using namespace std;

typedef double real_t;

template<typename T>
using NullableRef = std::optional<std::reference_wrapper<T>>;
