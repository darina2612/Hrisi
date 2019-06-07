#include "BinaryBooleanOperation.h"

#include <iostream>

BinaryBooleanOperation::BinaryBooleanOperation(BooleanExpression* left,
                                               BinaryOperationType op,
                                               BooleanExpression* right) :
                                               leftExpr(left), operation(op),
                                               rightExpr(right)
{

}

BinaryBooleanOperation::~BinaryBooleanOperation()
{
    delete leftExpr;
    delete rightExpr;
}

bool BinaryBooleanOperation::Evaluate() const
{
    bool leftExprValue = leftExpr->Evaluate();
    bool rightExprValue = rightExpr->Evaluate();

    return Evaluate(leftExprValue, rightExprValue);
}

void BinaryBooleanOperation::Print() const
{
    std::cout << "(";
    leftExpr->Print();
    PrintOperation();
    rightExpr->Print();
    std::cout << ")";
}

bool BinaryBooleanOperation::isTautology() const
{
    //TODO : Implement
    return false;
}

bool BinaryBooleanOperation::isContradiction() const
{
    //TODO : Implement
    return false;
}

bool BinaryBooleanOperation::isContingency() const
{
    return !(isTautology() || isContradiction());
}

bool BinaryBooleanOperation::Evaluate(bool left, bool right) const
{
    switch(operation)
    {
    case And:
        return left && right;

    case Or:
        return left || right;

    case ExclusiveOr:
        return (!left && right) || (right && !left);

    case IfThen:
        return right || !left;

    case IfAndOnlyIf:
        return right == left;

    default:
        std::cout << "Unknown binray operation!" << std::endl;
        return false;
    }
}

void BinaryBooleanOperation::PrintOperation() const
{
    switch(operation)
    {
    case And:
        std::cout << " && ";
        break;

    case Or:
        std::cout << " || ";
        break;

    case ExclusiveOr:
        std::cout << " ~ "; //maybe another symbol??
        break;

    case IfThen:
        std::cout << " => ";
        break;

    case IfAndOnlyIf:
        std::cout << " <=> ";
        break;

    default:
        break;
    }
}
