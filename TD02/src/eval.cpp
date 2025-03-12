#include "eval.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

std::vector<std::string> split_string(std::string const& s) // Code donné
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
    for (char c : s)
    {
        if (!std::isdigit(c) && c != '.')
        {
            return false;
        }
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens)
{
    std::stack<float> stack;

    for (const std::string& token : tokens)
    {
        if (is_floating(token))
        {
            stack.push(std::stof(token));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                std::cout << "Erreur : expression invalide (pas assez d'opérandes)." << std::endl;
            }

            // Code donné : Je récupère l'élément en haut de la pile
            float rightOperand = stack.top();
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand = stack.top();
            stack.pop();

            if (token == "+")
            {
                stack.push(leftOperand + rightOperand);
            }
            else if (token == "-")
            {
                stack.push(leftOperand - rightOperand);
            }
            else if (token == "*")
            {
                stack.push(leftOperand * rightOperand);
            }
            else if (token == "/")
            {
                if (rightOperand == 0)
                {
                    std::cout << "Erreur : division par zéro." << std::endl;
                }
                stack.push(leftOperand / rightOperand);
            }
        }
        else
        {
            std::cout << "Erreur : token " << token << " invalide." << std::endl;
        }
    }

    if (stack.size() != 1)
    {
        std::cout << "Erreur : expression invalide (trop d'opérandes)." << std::endl;
    }
    
    return stack.top();
}