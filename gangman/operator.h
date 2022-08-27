#include "Tensor.h"
#pragma once
#include <iostream>
#include <string>

class Operator{
    public:
    Operator(double define_value) : op_value(define_value), have_value(true){};
    Operator(Operator* op1) : input_ptr(op1){};

    virtual void Forward();
    virtual void Backward();

    void add();
    void mat_mul();

    double get_output();
    double get_grad();

    double get_value();


    // double init;

    double op_grad;
    double op_value;

    bool have_value = false;

    Operator* input_ptr;
    
};
    Operator& sin(Operator* op1);


 
