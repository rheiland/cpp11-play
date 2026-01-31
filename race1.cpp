// clang++ -g -fomit-frame-pointer -Xpreprocessor -fopenmp -m64 -std=c++11 -I/opt/homebrew/opt/libomp/include -w  -c race1.cpp
// clang++ -g -fomit-frame-pointer -Xpreprocessor -fopenmp -m64 -std=c++11 -I/opt/homebrew/opt/libomp/include -w  race1.cpp  -o race1

// clang++  -fomit-frame-pointer -Xpreprocessor -fopenmp -m64 -std=c++11 -I/opt/homebrew/opt/libomp/include -w -L/opt/homebrew/opt/libomp/lib -lomp race1.cpp  -o race1


// yipeee?
//(base) M1P~/git/cpp11-play$ clang++ -Xpreprocessor -fopenmp -fsanitize=thread -g -O1 -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib  -lomp race1.cpp



#include <iostream>
#include "omp.h"

int main() {
    int total = 0;
    // Set the number of threads for demonstration (optional)
    omp_set_num_threads(4); 
//    omp_set_num_threads(1); 

    #pragma omp parallel for
    for (int i = 0; i < 100000; ++i) {
        total++; // Race condition here
    }

    std::cout << "Expected total: 100000" << std::endl;
    std::cout << "Actual total: " << total << std::endl;

    return 0;
}
