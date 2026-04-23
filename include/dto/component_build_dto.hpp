#pragma once

#include<global.hpp>

class Circuit;
class MNAEquation;

struct ComponentBuildDto {
    Circuit& circuit;
    MNAEquation& equation;
    real_t dt;
};