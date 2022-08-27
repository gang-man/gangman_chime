#include "operator.h"
#include "sin_op.h"

// Operator sin(Operator *op1) {
//   SinOp sin_op(op1);
//   return std::move(op1);
//   //   return *(new SinOp(op1));
// };

double Operator::GetValue() {
  if (have_value) {
    return op_value;
  }
  Forward();
  have_value = true;
  return op_value;
}

double Operator::GetGrad() {
  if (have_value) {
    return op_grad;
  }
  Backward();
  have_value = true;
  return op_grad;
}
