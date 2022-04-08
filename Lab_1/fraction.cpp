#include <iostream>
#include "fraction.h"

using namespace std;

// constructor
int Fraction::removedFractions_ = 0;

Fraction::Fraction(int newNumerator, int newDenominator, string newName) :
        numerator(newNumerator), denominator(newDenominator), fractionName(newName) {
}

// setters
void Fraction::setNumerator(int newNumerator) {
    numerator = newNumerator;
}

void Fraction::setDenominator(int newDenominator) {
    denominator = newDenominator;
}

// getters
int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

// print method
void Fraction::print() const {
    cout << numerator << "/" << denominator << "\n";
}

// static method
int Fraction::removedFractions() {
    return removedFractions_;
}

// destructor
Fraction::~Fraction() {
    removedFractions_++;
}

// save and load
void Fraction::save(ostream &os) const {
    os << numerator << "/" << denominator;
}

void Fraction::load(istream &is) {
    string fraction;
    getline(is, fraction);
    int i = fraction.find('/');
    numerator = stoi(fraction.substr(0, i));
    denominator = stoi(fraction.substr(i + 1, fraction.length()));
}

// fractionName
string Fraction::getFractionName() const {
    return fractionName;
}

// static methods
int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}