#include "operator.h"
#include "sin_op.h"

Operator& sin(Operator* op1){
    
    return *(new SinOp(op1));
    
};

double Operator::get_value(){
    if(have_value){
        return op_value;
    }
    Forward();
    have_value = true;
    return op_value;
}