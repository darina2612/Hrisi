#pragma once

class BooleanExpression
{
public:
    virtual ~BooleanExpression(){}

    virtual bool Evaluate() const = 0;

    virtual void Print() const = 0;

    virtual bool isTautology() const = 0;
    virtual bool isContradiction() const = 0;
    virtual bool isContingency() const = 0;
};
