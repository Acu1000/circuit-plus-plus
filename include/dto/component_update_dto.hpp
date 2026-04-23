#pragma once

#include<global.hpp>

class Circuit;
class MNAEquation;

struct ComponentUpdateDto {
    Circuit& circuit;
    MNAEquation& equation;
    real_t dt;
    long elapsed_steps;
};