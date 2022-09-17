// #include "bin.h"
#include "bfc_allocator.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#include "malloc.h"
#include <memory>
  
int main() {

 

  // std::cout << (2 != 0) << std::endl;
  // void *ptr = malloc((2560100010000000000));
  // while(ptr == nullptr){

  //   std::cout << "NULL" << std::endl;
  // }
  // BFCAllocator bfc;
  // bfc.allocate(256);


  // int a = 1;
  // int b = 2;
  // int c = 3;
  // int d = 4;
  std::vector<int> v;

  std::fill_n(std::back_inserter(v), 10, 0);

  for(std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
    std::cout << *iter << std::endl;
  }
  v.push_back(4);
    std::cout << v[10] << std::endl;


  void* ptr = malloc(1000000000000000000);
  if(ptr == nullptr){
    std::cout << "NULL" << std::endl;
  }
 
  free(ptr);

  // v.push_back(b);
  // v.push_back(c);

  // std::vector<int>::iterator iter = v.begin();

  //   v.insert(iter, d);
    
  

  // std::cout << v.size() << std::endl;
  // std::cout << v[0] << std::endl;



  // int *temp = v[0];
  // std::cout << *v[0] << "+" << *v[1] << *v[2] << std::endl;

  // v.insert(v.begin() + 1, &d);
  // std::cout << *v[0] << "+" << *v[1] << *v[2] << std::endl;

  
  

}