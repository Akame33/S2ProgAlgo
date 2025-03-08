#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

// Exercice 1
Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}


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

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

// Exercice 3
bool operator==(Fraction const& f1, Fraction const& f2) {
    Fraction simplifyF1 = simplify(f1);
    Fraction simplifyF2 = simplify(f2);

    return simplifyF1.numerator == simplifyF2.numerator && simplifyF1.denominator == simplifyF2.denominator;
}


bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

// Exercice  4
bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator < f1.denominator * f2.numerator;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return !(f2 < f1); 
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return f2 < f1; 
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2); 
}

// Exercice 5 
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

// Réécriture des opérateurs binaires en utilisant les opérateurs d'affectation
Fraction operator+(Fraction f1, Fraction const& f2) {
    return f1 += f2;
}

Fraction operator-(Fraction f1, Fraction const& f2) {
    return f1 -= f2;
}

Fraction operator*(Fraction f1, Fraction const& f2) {
    return f1 *= f2;
}

Fraction operator/(Fraction f1, Fraction const& f2) {
    return f1 /= f2;
}


// Exercice 6
float Fraction::to_float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}