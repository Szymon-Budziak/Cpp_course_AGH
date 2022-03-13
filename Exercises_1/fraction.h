#ifndef TASK1_FRACTION_H
#define TASK1_FRACTION_H

#include <istream>
#include <iosfwd>
#include <string>

#define IMPLEMENTED_classFractionExists 1
#define IMPLEMENTED_hasNumeratorAndDenominator 1
#define IMPLEMENTED_hasDefaultConstructor 1
#define IMPLEMENTED_hasConstructorWhichInitialiseFields 1
#define IMPLEMENTED_hasGettersAndSetters 1
#define IMPLEMENTED_hasPrintFunction 1
#define IMPLEMENTED_counterOfDestructedFractionsImplemented 1
#define IMPLEMENTED_readWriteImplemented 1
#define IMPLEMENTED_fractionNameSettableFromConstructor 1
#define IMPLEMENTED_fractionConstStaticFieldsImplemented 1


class Fraction {
protected:
    int numerator, denominator;
    static int removedFractions_;
    const std::string fractionName;
    static const int invalidDenominatorValue = 0;
    static constexpr int defaultDenominatorValue = 1;
public:
    // constructor
//    Fraction();

    Fraction(int numerator = 0, int denominator = 1, std::string fractionName = "fraction");

    // setters
    void setNumerator(int numerator);

    void setDenominator(int denominator);

    // getters
    int getNumerator() const;

    int getDenominator() const;

    // print method
    void print() const;

    // static method
    static int removedFractions();

    // destructor
    ~Fraction();

    // save and load
    void save(std::ostream &os) const;

    void load(std::istream &is);

    // fractionName
    std::string getFractionName() const;

    // static methods
    static int getInvalidDenominatorValue();

    constexpr static int getDefaultDenominatorValue() {
        return defaultDenominatorValue;
    };

};

#endif // TASK1_FRACTION_H