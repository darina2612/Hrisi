#include "BooleanVariable.h"

#include <iostream>

BooleanVariable::BooleanVariable(bool v, char n) : value(v), name(n)
{
}

bool BooleanVariable::Evaluate() const
{
    return value;
}

void BooleanVariable::Print(bool printNames) const
{
    if(!printNames)
    {
        std::cout << value;
    }
    else
    {
        if(name == '\0')
            std::cout << "??";
        else
            std::cout << name;
    }
}

bool BooleanVariable::IsTautology() const
{
    return false;
}

bool BooleanVariable::IsContradiction() const
{
    return false;
}

bool BooleanVariable::IsContingency() const
{
    return true;
}

char BooleanVariable::GetName() const
{
    return name;
}
