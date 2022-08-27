#include <cmath>
#include <math.h>
#include "sin_op.h"



void SinOp::Forward() {
    op_value = sin(input_ptr->get_value());
    // this->op_value = sin(input_ptr->get_output());
}
int a = pow(2, 3);

