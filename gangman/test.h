#pragma once
#include <cstdio>
#include <iostream>



class Test0 {
public:
  int a;
  int b;
  Test0(int a) : a(a){};

   void Print(){
    std::cout << "Test0" << std::endl;}
    // return;};

};

class Test  {
public:
  int a;
  int b;
  Test(int a) : a(a){};

   void Print() {
    std::cout << "Test" << std::endl;}
    // return;};

//   Test *inpdut_ptr;
};

class Tester : public Test {
public:
  Tester(int a) : Test(a){};
  void Print()  { printf("a = %d\n", a); }
};
