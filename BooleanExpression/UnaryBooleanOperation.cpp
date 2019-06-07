#include "UnaryBooleanOperation.h"

#include <iostream>

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

void UnaryBooleanOperation::Print() const
{
    PrintOperationSymbol();
    expression->Print();
}

bool UnaryBooleanOperation::isTautology() const
{
    if(operation == Not)
        return !expression->isContradiction();

    return false;
}

bool UnaryBooleanOperation::isContradiction() const
{
    if(operation == Not)
        return !expression->isTautology();

    return false;
}

bool UnaryBooleanOperation::isContingency() const
{
    return !(expression->isTautology() || expression->isContradiction());
}

void UnaryBooleanOperation::PrintOperationSymbol() const
{
    std::cout << (operation == Not ? '!' : ' ');
}
