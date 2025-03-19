#include "exo1.cpp"

int main() 
{
    std::vector<int> vector1 {6, 2, 8, 1, 5, 3, 9};

    bubble_sort(vector1);

    std::vector<int> vector2 {7, 62, 10, 89, 2, 47, 1, 25, 25, 3, 0, 9};

    bubble_sort(vector2);

    std::vector<int> vector3 {22, 5, 78};

    bubble_sort(vector3);

    return 0;
}