#include "bin.h"
#include "chunk.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <vector>

int main() {

  // std::cout << (2 != 0) << std::endl;
  // void *ptr = malloc((2560100010000000000));
  // while(ptr == nullptr){

  //   std::cout << "NULL" << std::endl;
  // }
  // BFCAllocator bfc;
  // bfc.allocate(256);
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  std::vector<int *> v;
  v.push_back(&a);
  v.push_back(&b);
  v.push_back(&c);

  int *temp = v[0];
  std::cout << *v[0] << "+" << *v[1] << *v[2] << std::endl;

  v.insert(v.begin() + 1, &d);
  std::cout << *v[0] << "+" << *v[1] << *v[2] << std::endl;
}