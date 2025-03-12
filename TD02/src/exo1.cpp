#include "eval.cpp"

int main()
{
    std::string npi;
    std::cout << "Entrez votre expression arithmétique en notation polonaise inversée (avec des espaces) : ";
    std::getline(std::cin, npi);

    std::vector<std::string> tokens = split_string(npi);
    float result = npi_evaluate(tokens);

    std::cout << "Résultat : " << result << std::endl;

    return 0;
}