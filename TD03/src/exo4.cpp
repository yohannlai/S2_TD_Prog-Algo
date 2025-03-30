#include <iostream>
#include <vector>

int search(const std::vector<int>& vec, int value)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (vec[middle] == value)
        {
            return middle;
        }
        else if(vec[middle] < value)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return - 1;
}

void test_search(const std::vector<int>vec, int value)
{
    int result = search(vec, value);
    if (result != -1)
    {
        std::cout << "Valeur " << value << " trouvée à l'indice " << result << ".\n";
    }
    else
    {
        std::cout << "Valeur " << value << " non trouvée.\n";
    }
}

int main()
{
    std::vector<std::vector<int>> test_vectors = {
        {1, 2, 2, 3, 4, 8, 12},
        {1, 2, 3, 3, 6, 14, 12, 15},
        {2, 2, 3, 4, 5, 8, 12, 15, 16},
        {5, 6, 7, 8, 9, 10, 11, 12, 13},
        {1, 2, 3, 4, 5, 6, 7, 8, 9}
    };

    std::vector<int> search_values = {8, 15, 16, 6, 10};

    for (size_t i = 0; i < test_vectors.size(); i++)
    {
        test_search(test_vectors[i], search_values[i]);
    }

    return 0;
}