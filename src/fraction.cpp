#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    return os << f.numerator << "/" << f.denominator;
}

Fraction& Fraction::operator+=(Fraction const& f) {
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;
    *this = simplify(*this);
    return *this;
}

Fraction& Fraction::operator-=(Fraction const& f) {
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator = denominator * f.denominator;
    *this = simplify(*this);
    return *this;
}

Fraction& Fraction::operator*=(Fraction const& f) {
    numerator *= f.numerator;
    denominator *= f.denominator;
    *this = simplify(*this);
    return *this;
}

Fraction& Fraction::operator/=(Fraction const& f) {
    numerator *= f.denominator;
    denominator *= f.numerator;
    *this = simplify(*this);
    return *this;
}

// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
//
// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
//
// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }
//
// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return Fraction(f1) += f2;
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return Fraction(f1) -= f2;
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return Fraction(f1) *= f2;
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return Fraction(f1) /= f2;
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