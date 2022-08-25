// #include "Tensor.h"
#include <iostream>
#include <thread>

void Dowork1(){
// using namespace std::literals::chrono_literals;

    while(true){
        std::cout << "Working/n";
        // std::this_thread::sleep_for(1s);
    }
}

// void Dowork2(){
// // using namespace std::literals::chrono_literals;

//     while(true){
//         std::cout << "Gang...Man/n";
//         // std::this_thread::sleep_for(1s);
//     }
// }
int main(){
    // std:: thread worker1(Dowork1);
    
    // worker1.join();

    // std:: thread worker2(Dowork2);

    
    // std::cout << "Finished" << std::endl;

    // std::cin.get();
    std::cout << "Hello World" << std::endl;

}