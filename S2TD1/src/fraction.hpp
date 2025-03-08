#pragma once
#include <iostream>


struct Fraction {
    unsigned int numerator { 0 };
    unsigned int denominator { 1 };

    void display();

    // Exercice 5 
    Fraction& operator+=(Fraction const& f);
    Fraction& operator-=(Fraction const& f);
    Fraction& operator*=(Fraction const& f);
    Fraction& operator/=(Fraction const& f);

    // Exercice 6
    float to_float() const;
    operator float() const;
};


// Exercice 1
Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);


// Exercice 2
std::ostream& operator<<(std::ostream& os, const Fraction& f);


// Exercice 3
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

// Exercice 4
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);







