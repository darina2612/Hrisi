#pragma once

#include <BooleanExpression.h>

enum UnaryOperationType
{
    NoneUnary= -1,
    Not,
};

class UnaryBooleanOperation : public BooleanExpression
{
public:
    UnaryBooleanOperation(UnaryOperationType op, BooleanExpression* expr);

    virtual ~UnaryBooleanOperation();

    virtual bool Evaluate() const;

    virtual void Print() const;

    virtual bool isTautology() const;
    virtual bool isContradiction() const;
    virtual bool isContingency() const;

private:
    void PrintOperationSymbol() const;

    UnaryOperationType operation;
    BooleanExpression* expression;
};
