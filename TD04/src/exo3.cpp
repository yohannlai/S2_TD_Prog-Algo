#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool palindrome(const std::string& str)
{
    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

int main() {
    std::cout << "Entrez un mot : ";
    std::string word;
    std::getline(std::cin, word);

    if (palindrome(word) == true)
    {
        std::cout << word << " est un palindrome.\n"; 
    }
    else
    {
        std::cout << word << " n'est pas un palindrome.\n"; 
    }

    return 0;
}