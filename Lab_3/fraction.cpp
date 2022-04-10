#include <stdexcept>
#include <numeric>

#include "fraction.h"

// constructor
Fraction::Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
}

// getters
int Fraction::numerator() const noexcept {
    return numerator_;
}

int Fraction::denominator() const noexcept {
    return denominator_;
}

// setters
void Fraction::setNumerator(int numerator) noexcept {
    numerator_ = numerator;
}

void Fraction::setDenominator(int denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    denominator_ = denominator;
}

// operator +
Fraction Fraction::operator+(const Fraction &other) const {
    int new_numerator = numerator_ * other.denominator() + other.numerator() * denominator_;
    int new_denominator = denominator_ * other.denominator();
    if (new_denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    Fraction new_fraction = simplifyFraction(Fraction(new_numerator, new_denominator));
    return new_fraction;
}

// operator *
Fraction Fraction::operator*(const Fraction &other) const {
    int new_numerator = numerator_ * other.numerator();
    int new_denominator = denominator_ * other.denominator();
    if (new_denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    Fraction new_fraction = simplifyFraction(Fraction(new_numerator, new_denominator));
    return new_fraction;
}

// simplify fraction
Fraction Fraction::simplifyFraction(Fraction fraction) {
    int numerator = fraction.numerator();
    int denominator = fraction.denominator();
    int divisor = std::gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    return Fraction(numerator, denominator);
}