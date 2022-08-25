#include "Tensor.h"

class Operator{
    public:
    Operator(class op1, class op2, Tensor tensor);
    Operator(class op1);
    Operator(class op1, class op2);
    Operator(Tensor tensor1, Tensor tensor2);
    Operator();

    void add();
    void mat_mul();
};