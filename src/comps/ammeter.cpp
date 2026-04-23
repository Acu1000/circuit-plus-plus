#include<comps/ammeter.hpp>

#include<simulation/mna_equation.hpp>

Ammeter::Ammeter(ComponentID p_id) : DCPower(p_id, 0)
{
}

void Ammeter::update(ComponentUpdateDto dto)
{
    last_current = dto.equation.get_voltage_source_current(voltage_source_id);
}

real_t Ammeter::measure()
{
    return last_current;
}
