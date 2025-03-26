#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> num_array(10);

    std::random_device rd {}; // Objet permettant de générer une graine aléatoire (similaire à srand(time(nullptr)))
    std::mt19937 gen(rd()); // Générateur de nombres pseudo-aléatoires Mersenne Twister (un des générateurs les plus performants)
    std::uniform_int_distribution<> dis(0, 100); // Distribution uniforme entre 0 et 100

    for (int i = 0; i < num_array.size(); i++)
    {
        int random_number { dis(gen) }; // Génération d'un nombre aléatoire
        num_array[i] = random_number;
    }
    
    std::vector<int>::iterator begin_iterator { num_array.begin() };
    std::vector<int>::iterator end_iterator { num_array.end() };

    std::cout << "Vecteur: [";
    for (auto it = begin_iterator; it != end_iterator; it++)
    {
        if (*it != num_array.back())
        {
            std::cout << *it << " ";
        }
        else
        {
            std::cout << num_array.back() << "]\n";
        }
    }

    int value;
    int choice;
    do {
        std::cout << "Entrez un nombre entier entre 0 et 100 pour savoir s'il est dans le vecteur : ";
        std::cin >> value;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur : nombres entiers uniquement.\n";
            break;
        }

        auto finder { std::find(begin_iterator, end_iterator, value) };
        if (finder != end_iterator)
        {
            std::cout << value << " est présent dans le vecteur.\n";
        }
        else
        {
            std::cout << value << " n'est pas présent dans le vecteur.\n";
        }

        std::cout << "Continuer à chercher ?    1. Oui    2. Non\n";
        std::cin.clear();
        std::cin >> choice;
        if(choice != 1 && choice != 2 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur.\n";
            break;
        }
    } while (choice != 2);
}