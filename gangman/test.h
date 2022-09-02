#pragma once
#include <cstdio>
#include <iostream>

class Test0 {
public:
  int a;
  int b;
  Test0(int a) : a(a){};

  virtual void Print() { std::cout << "Test0" << std::endl; }
  // return;};
};

class Test {
public:
  int a;
  int b;
  Test(int a) : a(a){};

  virtual void Print() { std::cout << "Test" << std::endl; }


  Test *inpdut_ptr;
};

class Tester : public Test {
public:
  void Print() { printf("a = %d\n", a); }
  Tester(int a) : Test(a){};
};
