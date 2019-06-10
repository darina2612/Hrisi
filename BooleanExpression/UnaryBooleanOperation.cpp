#include "UnaryBooleanOperation.h"

#include <iostream>
#include <BooleanVariable.h>

UnaryBooleanOperation::UnaryBooleanOperation(UnaryOperationType op,
                                             BooleanExpression* expr) :
                                             operation(op), expression(expr)
{

}

UnaryBooleanOperation::~UnaryBooleanOperation()
{
    delete expression;
}

bool UnaryBooleanOperation::Evaluate() const
{
    if(operation == Not)
        return !(expression->Evaluate());

    std::cout << "Unknown unaray operation!" << std::endl;
    return expression->Evaluate();
}

void UnaryBooleanOperation::Print(bool printNames) const
{
    PrintOperationSymbol();
    expression->Print(printNames);
}

bool UnaryBooleanOperation::IsTautology() const
{
    if(operation == Not)
    {
        const BooleanVariable* var = dynamic_cast<const BooleanVariable*>(expression);
        if(var != nullptr)
            return false;

        return !expression->IsContradiction();
    }

    return false;
}

bool UnaryBooleanOperation::IsContradiction() const
{
    if(operation == Not)
    {
        const BooleanVariable* var = dynamic_cast<const BooleanVariable*>(expression);
        if(var != nullptr)
            return false;

        return !expression->IsTautology();
    }

    return false;
}

bool UnaryBooleanOperation::IsContingency() const
{
    return !(expression->IsTautology() || expression->IsContradiction());
}

const BooleanExpression* UnaryBooleanOperation::GetParameterExpression() const
{
    return expression;
}

UnaryOperationType UnaryBooleanOperation::GetOperationType() const
{
    return operation;
}

void UnaryBooleanOperation::PrintOperationSymbol() const
{
    std::cout << (operation == Not ? '!' : ' ');
}
