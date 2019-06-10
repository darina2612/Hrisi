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

    virtual void Print(bool printNames = false) const;

    virtual bool IsTautology() const;
    virtual bool IsContradiction() const;
    virtual bool IsContingency() const;

    const BooleanExpression* GetParameterExpression() const;
    UnaryOperationType GetOperationType() const;

private:
    void PrintOperationSymbol() const;

    UnaryOperationType operation;
    BooleanExpression* expression;
};
