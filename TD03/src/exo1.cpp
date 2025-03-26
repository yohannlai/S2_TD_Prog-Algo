#include "sort.hpp"
#include "display.hpp"

void bubble_sort(std::vector<int> & vec)
{
    std::cout << "Tableau avant tri à bulles : ";
    print_vector(vec);
    std::cout << std::endl;

    int n = vec.size();
    bool swapped {};

    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++){
            if(vec[i] > vec[i + 1]){
                std::swap(vec[i], vec[i + 1]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);

    std::cout << "Tableau après tri à bulles : ";
    print_vector(vec);
    std::cout << std::endl << std::endl;
}