#include <iostream>
#include <string>
#include <vector>

// Code donné en séance de cours
size_t folding_string_hash(std::string const& s, size_t max)
{
    size_t hash {0};
    for (char c : s)
    {
        hash += static_cast<size_t>(c);
        hash %= max;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max)
{
    size_t hash {0};
    for (size_t i = 0; i < s.size(); i++)
    {
        hash += static_cast<size_t>(s[i] * (i + 1));
        hash %= max;
    }
    return hash;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m)
{
    size_t hash {0};
    size_t power {1};
    for (char c : s)
    {
        hash += (static_cast<size_t>(c) * power);
        hash %= m;
        power *= p;
    }
    return hash;
}

int main()
{
    std::vector<std::string> strings {"IMAC", "MICA", "BATMAN", "FOREVER"};

    // Test fonction folding_string_hash (1.)
    for (std::string const& s : strings)
    {
        size_t const hash_value1 = folding_string_hash(s, 1024);
        std::cout << "La valeur hachée avec la fonction du 1. de " << s << " est " << hash_value1 << std::endl;
    }
    std::cout << std::endl;

    // Test fonction folding_string_ordered_hash (2.)
    for (std::string const& s : strings)
    {
        size_t const hash_value2 = folding_string_ordered_hash(s, 1024);
        std::cout << "La valeur hachée avec la fonction du 2. de " << s << " est " << hash_value2 << std::endl;
    }
    std::cout << std::endl;

    //Test fonction polynomial_rolling_hash (3.)
    for (std::string const& s : strings)
    {
        size_t const hash_value3 = polynomial_rolling_hash(s, 31, 1e9 + 9);
        std::cout << "La valeur hachée avec la fonction du 3. de " << s << " est " << hash_value3 << std::endl;
    }

    return 0;
}