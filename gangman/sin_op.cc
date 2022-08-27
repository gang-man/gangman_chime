#include "sin_op.h"
#include <cmath>
#include <math.h>

void SinOp::Forward() {
  std::cout << "Sin_Forward" << std::endl;
  op_value = sin(input_ptr->GetValue());
  // this->op_value = sin(input_ptr->get_output());
}

void SinOp::Backward() {
  //   op_grad = cos(input_ptr->GetValue());
  // this->op_grad = cos(input_ptr->get_output());
}

SinOp sin(Operator *op1) {
  SinOp sin_op(op1);
  return std::move(op1);
  //   return *(new SinOp(op1));
};
