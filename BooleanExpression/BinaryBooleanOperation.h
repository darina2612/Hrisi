#pragma once

#include "BooleanExpression.h"

enum BinaryOperationType
{
    NoneBinary = -1,
    And,
    Or,
    ExclusiveOr,
    IfThen,
    IfAndOnlyIf,
};

class BinaryBooleanOperation : public BooleanExpression
{
public:
    BinaryBooleanOperation(BooleanExpression* left, BinaryOperationType op, BooleanExpression* right);

    virtual ~BinaryBooleanOperation();

    virtual bool Evaluate() const;

    virtual void Print() const;

    virtual bool isTautology() const;
    virtual bool isContradiction() const;
    virtual bool isContingency() const;

private:
    bool Evaluate(bool left, bool right) const;
    void PrintOperation() const;

    BooleanExpression* leftExpr;
    BinaryOperationType operation;
    BooleanExpression* rightExpr;
};
