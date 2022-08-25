#include <algorithm>
#include "Tensor.h"
#include <iostream>
#include <random>

// Tensor *tnsor = new Tensor(5, 4);

Tensor::Tensor(int input_col, int input_row):
col(input_col), row(input_row)
{
    data.reset(new float[col * row]);
    std::default_random_engine e;
    std::uniform_real_distribution<> uniform_real_data(0, 1);
    e.seed(time(0));
    for(int i = 0; i < col * row; i++){
        std::cout << uniform_real_data(e) << std::endl;
    }

}
// int main(){

//     Tensor tensor_test = Tensor(5, 4);

// }