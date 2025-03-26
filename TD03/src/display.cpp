#include "display.hpp"

void print_vector(const std::vector<int> & vec)
{
    int n = vec.size();
    std::cout << "[";
    for (int i = 0; i < n - 1; i++){
        std::cout << vec[i] << ", ";
    }
    std::cout << vec.back() << "]";
}

void print_vector(const std::vector<float> & vec)
{
    int n = vec.size();
    std::cout << "[";
    for (int i = 0; i < n - 1; i++){
        std::cout << vec[i] << ", ";
    }
    std::cout << vec.back() << "]";
}