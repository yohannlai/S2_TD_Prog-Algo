#include "exo1.cpp"
#include "exo2.cpp"

int main() 
{
    std::vector<int> vec1 {6, 2, 8, 1, 5, 3, 9};
    bubble_sort(vec1);

    std::vector<float> vec2 {6.4, 2.3, 8.6, 1.9, 5.0, 3.9, 9.3};
    quick_sort(vec2);

    std::vector<int> vec3 {7, 62, 10, 89, 2, 47, 1, 25, 25, 3, 0, 9};
    bubble_sort(vec3);

    std::vector<float> vec4 {7.7, 62.4, 10.5, 89.9, 2.1, 47.2, 1.3, 25.4, 25.3, 3.4, 0.1, 9.8};
    quick_sort(vec4);

    std::vector<int> vec5 {22, 5, 78};
    bubble_sort(vec5);

    std::vector<float> vec6 {22.3, 5.6, 78.8};
    quick_sort(vec6);

    return 0;
}