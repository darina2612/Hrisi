#pragma once

#include "BooleanExpression.h"

class BooleanVariable : public BooleanExpression
{
public:
    BooleanVariable(bool v = false);

    virtual bool Evaluate() const;

    virtual void Print() const;

    virtual bool isTautology() const;
    virtual bool isContradiction() const;
    virtual bool isContingency() const;

private:
    bool value;
};

