#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> num_array(10);

    // Code donné dans les "Retours généraux"
    std::random_device rd {}; // Objet permettant de générer une graine aléatoire (similaire à srand(time(nullptr)))
    std::mt19937 gen(rd()); // Générateur de nombres pseudo-aléatoires Mersenne Twister (un des générateurs les plus performants)
    std::uniform_int_distribution<> dis(0, 100); // Distribution uniforme entre 0 et 100

    for (size_t i = 0; i < num_array.size(); i++)
    {
        int random_number { dis(gen) }; // Génération d'un nombre aléatoire
        num_array[i] = random_number;
    }
    
    std::vector<int>::iterator begin_it { num_array.begin() };
    std::vector<int>::iterator end_it { num_array.end() };

    // Affichage du vecteur avec les itérateurs
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

    int value;
    int choice;
    do {
        std::cout << "Entrez un nombre entier entre 0 et 100 pour savoir s'il est dans le vecteur : ";
        std::cin >> value;

        // Gestion de l'erreur pour la saisie des nombres
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur : nombres entiers uniquement.\n";
            break;
        }

        // Chercher si le nombre est présent
        auto finder { std::find(begin_it, end_it, value) };
        if (finder != end_it)
        {
            std::cout << value << " est présent dans le vecteur.\n";

            // Compter le nombre d'occurrences du nombre
            int count = std::count(begin_it, end_it, value);
            std::cout << value << " apparaît " << count << " fois dans le vecteur.\n";
        }
        else
        {
            std::cout << value << " n'est pas présent dans le vecteur.\n";
        }

        // Pour continuer à chercher
        std::cout << "Continuer à chercher ?    1. Oui    2. Non\n";
        std::cin.clear();
        std::cin >> choice;
        // Gestion de l'erreur pour le choix
        if(choice != 1 && choice != 2 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur.\n";
            break;
        }
    } while (choice != 2);

    // Trier le vecteur
    std::sort(begin_it, end_it);
    std::cout << "Vecteur trié : [";
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

    // Sommer les éléments du vecteur
    int sum = std::accumulate(begin_it, end_it, 0);
    std::cout << "Somme des éléments du vecteur : " << sum << std::endl;

    return 0;
}