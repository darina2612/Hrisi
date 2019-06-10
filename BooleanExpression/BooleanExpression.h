#pragma once

class BooleanExpression
{
public:
    virtual ~BooleanExpression(){}

    virtual bool Evaluate() const = 0;

    virtual void Print(bool printNames = false) const = 0;

    virtual bool IsTautology() const = 0;
    virtual bool IsContradiction() const = 0;
    virtual bool IsContingency() const = 0;
};
