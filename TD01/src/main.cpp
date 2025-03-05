#include "fraction.hpp"
#include <iostream>

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1 << std::endl;

    std::cout << "f2 = " << f2 << std::endl;

    std::cout << "f1 + f2 = " << (f1 + f2) << std::endl;

    std::cout << "f1 - f2 = " << (f1 - f2) << std::endl;

    std::cout << "f1 * f2 = " << (f1 * f2) << std::endl;

    std::cout << "f1 / f2 = " << (f1 / f2) << std::endl;

    Fraction f3 { 1, 6 };
    Fraction f4 { 2, 6 };
    std::cout << "1/6 + 2/6 = " << f3 + f4 << std::endl;

    std::cout << "1/6 == 2/6 : " << (f3 == f4) << std::endl;

    std::cout << "1/6 == 1/6 : " << (f3 == f3) << std::endl;

    std::cout << "1/6 != 2/6 : " << (f3 != f4) << std::endl;

    std::cout << "2/6 != 2/6 : " << (f4 != f4) << std::endl;

    std::cout << "1/6 < 2/6 : " << (f3 < f4) << std::endl;

    std::cout << "1/6 <= 2/6 : " << (f3 <= f4) << std::endl;

    std::cout << "1/6 <= 1/6 : " << (f3 <= f3) << std::endl;

    std::cout << "1/6 > 2/6 : " << (f3 > f4) << std::endl;

    std::cout << "2/6 > 1/6 : " << (f4 > f3) << std::endl;

    std::cout << "1/6 >= 2/6 : " << (f3 >= f4) << std::endl;

    std::cout << "1/6 >= 1/6 : " << (f3 >= f3) << std::endl;

    Fraction f5 { 1, 3 };

    f5 += f3;
    std::cout << "1/3 += 1/6 : " << f5 << std::endl;

    f5 -= f3;
    std::cout << "1/2 -= 1/6 : " << f5 << std::endl;

    f5 *= f3;
    std::cout << "1/3 *= 1/6 : " << f5 << std::endl;

    f5 /= f3;
    std::cout << "1/18 /= 1/6 : " << f5 << std::endl;

    Fraction f6 { 3, 2 };
    std::cout << "3/2 as float : " << static_cast<float>(f6) << std::endl;

    Fraction f7 { 5, 3 };
    std::cout << "5/3 as float : " << static_cast<float>(f7) << std::endl;

    Fraction f8 { 7, 4 };
    std::cout << "7/4 as float : " << static_cast<float>(f8) << std::endl;

    Fraction f9 { 10, 2 };
    std::cout << "10/2 as float : " << static_cast<float>(f9) << std::endl;

    Fraction f10 { 0, 1 };
    std::cout << "0/1 as float : " << static_cast<float>(f10) << std::endl;
    
    return 0;
}