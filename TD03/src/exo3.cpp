#include <cstdlib>
#include "ScopedTimer.hpp"
#include "exo1.cpp"
#include "exo2.cpp"
#include "display.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

std::vector<float> generate_random_float_vector(size_t const size, float const max = 100.0f) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return static_cast<float>(std::rand()) / RAND_MAX * max; });
    return vec;
}

int main()
{
    std::vector<int> array = generate_random_vector(30);
    std::vector<int> original_array = array;

    {
        ScopedTimer timer("Tri à bulles");
        bubble_sort(array);
    }

    array = original_array;

    std::cout << "Tableau avant tri standard : ";
    print_vector(array);
    std::cout << std::endl;

    {
        ScopedTimer timer("Bibliothèque standard");
        std::sort(array.begin(), array.end());
    }

    std::cout << "Tableau après tri standard : ";
    print_vector(array);
    std::cout << std::endl << std::endl;    

    std::vector<float> float_array = generate_random_float_vector(30);
    std::vector<float> original_float_array = float_array;

    {
        ScopedTimer timer("Tri rapide");
        quick_sort(float_array);
    }

    float_array = original_float_array;

    std::cout << "Tableau avant tri standard : ";
    print_vector(float_array);
    std::cout << std::endl;

    {
        ScopedTimer timer("Bibliothèque standard");
        std::sort(float_array.begin(), float_array.end());
    }

    std::cout << "Tableau après tri standard : ";
    print_vector(float_array);
    std::cout << std::endl << std::endl;    

    return 0;
}

// Que constatez-vous ?
// La fonction de tri standard de la bibliothèque C++ (std::sort) est beaucoup plus rapide que les algorithmes de tri implémentés manuellement.
// Le tri rapide (quick_sort) est même parfois plus lent que le tri à bulles (bubble_sort), tandis que std::sort est donc le plus performant.

// Que pouvez-vous en dire ?
// Cela est normal car std::sort est une implémentation qui a été optimisée pour maximiser les performances.
// En revanche, nos implémentations manuelles, bubble_sort et quick_sort, ne sont pas optimisées pour des performances élevées.
// Ainsi, la mauvaise performance de quick_sort s'explique par le choix de notre pivot, le premier élément du tableau.
// Pour améliorer quick_sort, comme dit dans le cours, l'idéal serait de choisir un pivot qui est proche de la valeur médiane du tableau 
// mais il est aussi dit que ces méthodes sont plus compliquées à mettre en oeuvre.
// En pratique, on utilisera donc std::sort pour des applications réelles en raison de sa fiabilité et de son efficacité.