#include <iostream>
#include <vector>
#include <numeric>

int sum_of_squares(const std::vector<int>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0, [](int acc, int x) { return acc + x * x; });
}

int product_of_evens(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 1, [](int acc, int x) {
        if (x % 2 == 0) {
            return acc * x;
    } else {
        return acc; 
    }
    });
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    std::vector<int>::iterator begin_it { nums.begin() };
    std::vector<int>::iterator end_it { nums.end() };

    std::cout << "Vecteur : [";
    for (auto it = begin_it; it != end_it; it++)
    {
        if (it + 1 != end_it)
        {
            std::cout << *it << " ";
        }
        else
        {
            std::cout << *it << "]\n";
        }
    }

    std::cout << "Sommes des carrés : " << sum_of_squares(nums) << std::endl;
    std::cout << "Produit des éléments pairs : " << product_of_evens(nums) << std::endl;

    return 0;
}