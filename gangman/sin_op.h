#pragma once
#include "operator.h"

class SinOp : public Operator {
public:

  // SinOp(Tensor tensor);

  SinOp(Operator *op1) : Operator(op1){};
  void Forward() override;
  void Backward() override;
  // void forward();
  // void backward();
};

  SinOp sin(Operator *op1);