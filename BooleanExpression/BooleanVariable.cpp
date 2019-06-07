#include "BooleanVariable.h"

#include <iostream>

BooleanVariable::BooleanVariable(bool v) : value(v)
{
}

bool BooleanVariable::Evaluate() const
{
    return value;
}

void BooleanVariable::Print() const
{
    std::cout << value;
}

bool BooleanVariable::isTautology() const
{
    return false;
}

bool BooleanVariable::isContradiction() const
{
    return false;
}

bool BooleanVariable::isContingency() const
{
    return true;
}
