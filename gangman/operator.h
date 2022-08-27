#include "Tensor.h"
// #include "gangman/sin_op.h"
// #include "sin_op.h"
#pragma once
#include <iostream>
#include <string>

class Operator {
public:
  Operator(double define_value) : op_value(define_value), have_value(true){};
  Operator(Operator *op1) : input_ptr(op1){};

  virtual void Forward() {
    std::cout << "Forward" << std::endl;
    return;
  };
  virtual void Backward() { return; };

  void add();
  void mat_mul();

  double GetOutput();
  double GetGrad();

  double GetValue();

  // double init;

  double op_grad;
  double op_value = 1.57;

  bool have_value = false;

  Operator *input_ptr;

//   friend Operator sin(Operator *op1);
};
