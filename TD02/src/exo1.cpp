#include <iostream>
#include "eval.cpp"

int main()
{
    std::string npi;
    std::cout << "Entrez votre expression arithmétique en notation polonaise inversée : ";
    std::getline(std::cin, npi);
    std::vector tokens = split_string(npi);
    

    return 0;
}