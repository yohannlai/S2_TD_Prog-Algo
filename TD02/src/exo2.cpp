#include "eval.cpp"

int main()
{
    std::string npi;
    std::cout << "Entrez votre expression arithmétique en notation polonaise inversée (avec des espaces) : ";
    std::getline(std::cin, npi);

    std::vector<std::string> words = split_string(npi);
    std::vector<Token> tokens = tokenize(words);
    float result = npi_evaluate_2(tokens);

    std::cout << "Résultat : " << result << std::endl;

    return 0;
}