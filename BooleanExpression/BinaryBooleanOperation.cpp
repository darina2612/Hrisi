#include "BinaryBooleanOperation.h"

#include <iostream>
#include <BooleanVariable.h>
#include <UnaryBooleanOperation.h>

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

void BinaryBooleanOperation::Print(bool printNames) const
{
    std::cout << "(";
    leftExpr->Print(printNames);
    PrintOperation();
    rightExpr->Print(printNames);
    std::cout << ")";
}

bool BinaryBooleanOperation::IsTautology() const
{
    if(IsSimpleTautology(leftExpr, rightExpr) || IsSimpleTautology(rightExpr, leftExpr))
        return true;

    if(operation == BinaryOperationType::And && leftExpr->IsTautology() && rightExpr->IsTautology())
        return true;

    if(operation == BinaryOperationType::Or && (leftExpr->IsTautology() || rightExpr->IsTautology()))
        return true;

    return false;
}

bool BinaryBooleanOperation::IsContradiction() const
{
    if(IsSimpleContradiction(leftExpr, rightExpr) || IsSimpleContradiction(rightExpr, leftExpr))
        return true;

    if(operation == BinaryOperationType::And && leftExpr->IsContradiction() && rightExpr->IsContradiction())
        return true;

    if(operation == BinaryOperationType::Or && (leftExpr->IsContradiction() && rightExpr->IsContradiction()))
        return true;

    return false;
}

bool BinaryBooleanOperation::IsContingency() const
{
    return !(IsTautology() || IsContradiction());
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
        std::cout << " + "; //maybe another symbol??
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

bool BinaryBooleanOperation::IsSimpleTautology(const BooleanExpression* left, const BooleanExpression* right) const
{
    //check if expression is of type a || !a
    return CheckOperation(left, right, BinaryOperationType::Or);
}

bool BinaryBooleanOperation::IsSimpleContradiction(const BooleanExpression* left, const BooleanExpression* right) const
{
    //check if expression is of type a && !a
    return CheckOperation(left, right, BinaryOperationType::And);
}


bool BinaryBooleanOperation::CheckOperation(const BooleanExpression* left, const BooleanExpression* right, BinaryOperationType op) const
{
    const BooleanVariable* var1 = dynamic_cast<const BooleanVariable*>(left);
    if(var1 == nullptr)
        return false;

    const UnaryBooleanOperation* unaryOp = dynamic_cast<const UnaryBooleanOperation*>(right);
    if(unaryOp == nullptr || unaryOp->GetOperationType() != UnaryOperationType::Not)
        return false;

    const BooleanVariable* var2 = dynamic_cast<const BooleanVariable*>(unaryOp->GetParameterExpression());
    if(var2 == nullptr)
        return false;

    return (operation == op) &&
           (var1->GetName() != '\0') &&
           (var1->GetName() == var2->GetName());
}
