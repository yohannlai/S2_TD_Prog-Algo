#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    return os << f.numerator << "/" << f.denominator;
}

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

bool operator==(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator == f2.numerator * f1.denominator;
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return (f1 < f2) || (f1 == f2);
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return !(f1 <= f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2);
}