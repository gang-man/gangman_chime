#include <iostream>
#include <memory>
#pragma once




class Tensor {

 public:
  int col;
  int row;
  std::unique_ptr<float> data;


  Tensor(int col, int row);
//   ATensor(int row, int col) : row(row), col(col) {
//     data.reset(new float[row * col]);
//   }
//   int row;
//   int col;
//   std::unique_ptr<float> data;
 





};