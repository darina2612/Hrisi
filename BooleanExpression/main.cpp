#include <iostream>
#include "BooleanVariable.h"
#include "UnaryBooleanOperation.h"
#include "BinaryBooleanOperation.h"

int main()
{
    BooleanVariable* p = new BooleanVariable(true);
    BooleanVariable* q = new BooleanVariable(false);
    UnaryBooleanOperation* notP = new UnaryBooleanOperation(Not, p);
    BinaryBooleanOperation* andOp = new BinaryBooleanOperation(q, And, notP);

    andOp->Print();

    std::cout << std::endl;
    std::cout << andOp->Evaluate();
    std::cout << std::endl;

    delete andOp;

    return 0;
}
