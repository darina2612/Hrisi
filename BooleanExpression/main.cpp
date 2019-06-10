#include <iostream>
#include "BooleanVariable.h"
#include "UnaryBooleanOperation.h"
#include "BinaryBooleanOperation.h"

int main()
{
    //Usage example
    //p && !p
    BooleanVariable* p = new BooleanVariable(true, 'p');
    BooleanVariable* p2 = new BooleanVariable(false, 'p');
    UnaryBooleanOperation* notP = new UnaryBooleanOperation(Not, p);
    BinaryBooleanOperation* andOp = new BinaryBooleanOperation(p2, And, notP);

    std::cout << "Expression: ";
    andOp->Print(true);
    std::cout << "\nExpression with concrete values: ";
    andOp->Print();

    std::cout << std::endl;
    std::cout << "Expression value : " << andOp->Evaluate() << std::endl;
    std::cout << "Expression is tautology : " << andOp->IsTautology() << std::endl;
    std::cout << "Expression is contradiction : " << andOp->IsContradiction()<< std::endl;
    std::cout << "Expression is contingency : " << andOp->IsContingency() << std::endl;
    std::cout << std::endl;

    delete andOp;

    return 0;
}
