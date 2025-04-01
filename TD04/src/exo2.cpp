#include <iostream>
#include <algorithm>
#include <string>

auto const is_space = [](char letter){ return letter == ' '; };

size_t first_word_length(const std::string& str)
{
    auto first = std::find_if_not(str.begin(), str.end(), is_space);
    auto last = std::find_if(first, str.end(), is_space);

    return std::distance(first, last);
}

std::vector<std::string> split_string(std::string const& str)
{
    std::vector<std::string> words;
    auto begin = str.begin();

    while (begin != str.end()) {
        begin = std::find_if_not(begin, str.end(), is_space);
        
        if (begin == str.end())
        {
            break;
        }
        auto end = std::find_if(begin, str.end(), is_space);
        words.push_back(std::string(begin, end));
        begin = end;
    }

    return words;
}

int main() {
    std::cout << "Entrez une phrase : ";
    std::string sentence;
    std::getline(std::cin, sentence);

    size_t length = first_word_length(sentence);
    std::cout << "La longueur (en lettres) du premier mot est : " << length << std::endl;

    auto words = split_string(sentence);
    std::cout << "Les mots de la phrase sont : ";
    for (size_t i = 0; i < words.size(); i++) 
    {
        if (i > 0) 
        {
            if (i == words.size() - 1)
            {
                std::cout << " et ";
            } 
            else 
            {
                std::cout << ", ";
            }
        }
        std::cout << words[i];
    }

    return 0;
}