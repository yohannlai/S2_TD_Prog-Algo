#include "sort.hpp"
#include <iostream>

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot)
{
    float pivot_value = vec[pivot];
    std::swap(vec[pivot], vec[right]);
    size_t index = left;

    for (size_t i = left; i < right; i++){
        if (vec[i] < pivot_value){
            std::swap(vec[i], vec[index]);
            index++;
        }
    }
    std::swap(vec[index], vec[right]);
    return index;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right)
{
    if (left < right){
        size_t pivot = right;
        size_t partition_index = quick_sort_partition(vec, left, right, pivot);

        if (partition_index > 0){
            quick_sort(vec, left, partition_index - 1);
        }
        quick_sort(vec, partition_index + 1, right);
    }
}

void quick_sort(std::vector<float> & vec) {
    if (!vec.empty()){
        std::cout << "Tableau avant tri rapide : ";
        print_vector(vec);
        std::cout << std::endl;
        
        quick_sort(vec, 0, vec.size() - 1);
        
        std::cout << "Tableau après tri rapide : ";
        print_vector(vec);
        std::cout << std::endl << std::endl;
    }
}