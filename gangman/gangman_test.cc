#include "gangman/sin_op.h"
#include "gangman/test.h"
#include "operator.h"
#include <iostream>

int main() {

  //   Test test(1);
  Test test = Test(5);
  Test tester = Tester(5);

  // Tester* tester_ptr0 = new Tester(5);

  // Test *test_ptr = &test;
  // Test *test_ptr1 = new Tester(5);

  // test_ptr->Print();
  // test_ptr1->Print();


  // test.Print();
  // tester.Print();
  // // tester.Print();
  
  Operator x = (1.57);
  // // std::cout << "x_op_value = " << x.GetValue() << std::endl;

  Operator y = sin(&x);
  

  // y.Forward();

  // double a = y.GetValue();
  // std::cout << "Sin(2) = " << a << std::endl;
  // //   std::cout << "y_op_value = " << y.op_value << std::endl;

  //   y.GetGrad();
}