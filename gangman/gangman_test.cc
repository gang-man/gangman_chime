#include "gangman/sin_op.h"
#include "gangman/test.h"
#include "operator.h"
#include <iostream>

int main() {

  //   Test test(1);
  Test0 test0 = Test0(5);
  Tester tester = Tester(5);

  test0.Print();
  tester.Print();
//   Operator x = (2.0);
//   std::cout << "x_op_value = " << x.GetValue() << std::endl;

//   Operator y = sin(&x);

//   y.Forward();
  

//   double a = y.GetValue();
//   std::cout << "Sin(2) = " << a << std::endl;
//   std::cout << "y_op_value = " << y.op_value << std::endl;

  //   y.GetGrad();
}