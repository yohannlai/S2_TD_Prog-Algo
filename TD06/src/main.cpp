// Exercice 2 : Utilisation

#include <iostream>
#include "node.cpp"

int main()
{
    Node* root = create_node(5);
    int values[] = {3, 7, 2, 4, 6, 8, 1, 9, 0};
    for (int value : values)
    {
        root->insert(value);
    }

    // Affichage de l'arbre binaire avec la fonction donnée pretty_print_left_right
    std::cout << std::endl;
    pretty_print_left_right(*root);
    std::cout << std::endl;

    std::cout << "Affichage dans l'ordre infixe : ";
    root->display_infix();
    std::cout << std::endl;

    // Bonus : Affichage de la valeur minimale et maximale de l'arbre
    std::cout << "Valeur minimale : " << root->min() << std::endl;
    std::cout << "Valeur maximale : " << root->max() << std::endl;

    std::vector<Node const*> pre = root->prefix();
    int sum = 0;
    for (Node const* node : pre)
    {
        sum += node->value;
    }
    std::cout << "Somme des valeurs : " << sum << std::endl;

    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;

    // On supprime l'arbre binaire pour libérer la mémoire
    delete_tree(root);

    return 0;
}