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

    virtual void Print(bool printNames = false) const;

    virtual bool IsTautology() const;
    virtual bool IsContradiction() const;
    virtual bool IsContingency() const;

private:
    bool Evaluate(bool left, bool right) const;
    void PrintOperation() const;
    bool IsSimpleTautology(const BooleanExpression* left, const BooleanExpression* right) const;
    bool IsSimpleContradiction(const BooleanExpression* left, const BooleanExpression* right) const;
    bool CheckOperation(const BooleanExpression* left, const BooleanExpression* right, BinaryOperationType op) const;

    BooleanExpression* leftExpr;
    BinaryOperationType operation;
    BooleanExpression* rightExpr;
};
