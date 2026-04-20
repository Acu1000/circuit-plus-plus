#include<comps/ammeter.hpp>

#include<simulation/mna_equation.hpp>

Ammeter::Ammeter(ComponentID p_id) : DCPower(p_id, 0)
{
}

void Ammeter::update(Circuit&, MNAEquation &p_equation, real_t)
{
    last_current = p_equation.get_voltage_source_current(voltage_source_id);
}

real_t Ammeter::measure()
{
    return last_current;
}
