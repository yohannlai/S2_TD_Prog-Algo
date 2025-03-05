#include "fraction.cpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1 << std::endl;

    std::cout << " f2 = " << f2 << std::endl;

    Fraction f3 { f1 + f2 };
    // f1 += f2;
    f1 = (f1 + f2);

    std::cout << "add(f1, f2) = " << f3 << std::endl;

    std::cout << "sub(f1, f2) = " << (f1 - f2) << std::endl;

    std::cout << "mul(f1, f2) = " << (f1 * f2) << std::endl;

    std::cout << "div(f1, f2) = " << (f1 / f2) << std::endl;

    std::cout << "add(1/6, 2/6) = ";
    Fraction f4 { 1, 6 };
    Fraction f5 { 2, 6 };
    std::cout << f4 + f5 << << std::endl;

    return 0;
}