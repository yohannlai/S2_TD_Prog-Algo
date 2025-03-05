#include "fraction.hpp"
#include <iostream>

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1 << std::endl;

    std::cout << "f2 = " << f2 << std::endl;

    // f1 += f2;

    std::cout << "f1 + f2 = " << (f1 + f2) << std::endl;

    std::cout << "f1 - f2 = " << (f1 - f2) << std::endl;

    std::cout << "f1 * f2 = " << (f1 * f2) << std::endl;

    std::cout << "f1 / f2 = " << (f1 / f2) << std::endl;

    Fraction f3 { 1, 6 };
    Fraction f4 { 2, 6 };
    std::cout << "1/6 + 2/6 = " << f3 + f4 << std::endl;

    return 0;
}