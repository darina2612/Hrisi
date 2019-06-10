#pragma once

#include "BooleanExpression.h"

class BooleanVariable : public BooleanExpression
{
public:
    BooleanVariable(bool v = false, char n = '\0');

    virtual bool Evaluate() const;

    virtual void Print(bool printNames = false) const;

    virtual bool IsTautology() const;
    virtual bool IsContradiction() const;
    virtual bool IsContingency() const;

    char GetName() const;

private:
    bool value;
    char name;//for the purposes of the checks for tautology and contradiction in complex expressions
};

