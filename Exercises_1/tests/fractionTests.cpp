#include <iostream>
#include <type_traits>
#include <gtest/gtest.h>

#if __has_include("../fraction.h")
    #include "../fraction.h"
#endif


namespace
{
using namespace std;
using namespace ::testing;

struct CoutBufferSentinel
{
    std::streambuf *oldCoutBuffer = nullptr;
    std::ostringstream newBuffer;

    CoutBufferSentinel()
    {
        oldCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(newBuffer.rdbuf());
    }

    ~CoutBufferSentinel()
    {
        std::cout.rdbuf(oldCoutBuffer);
    }

    auto getText() const
    {
        return newBuffer.str();
    }
};
} // namespace

struct FractionTester : public ::testing::Test
{    
};

TEST_F(FractionTester, classFractionExists)
{
    #if IMPLEMENTED_classFractionExists == 0
        ADD_FAILURE() << "Class not implemented!";
    #endif
}

TEST_F(FractionTester, hasNumeratorAndDenominator)
{
    #if IMPLEMENTED_hasNumeratorAndDenominator
        struct FractionWrapper: public Fraction
        {
            using Fraction::numerator;
            using Fraction::denominator;
        };
        ASSERT_TRUE(std::is_member_object_pointer_v<int(FractionWrapper::*)>);
        ASSERT_GT(sizeof(FractionWrapper::numerator),   0);
        ASSERT_GT(sizeof(FractionWrapper::denominator), 0);
    #else
        ADD_FAILURE() << "Numerator and denominator not implemented!";
    #endif
}

TEST_F(FractionTester, checkIfHasDefaultConstructor)
{
    #if IMPLEMENTED_classFractionExists && IMPLEMENTED_hasDefaultConstructor
        ASSERT_TRUE(is_default_constructible_v<Fraction>) << "Constructor not implemented";
    #else
        ADD_FAILURE() << "Class not implemented!";
    #endif
}

TEST_F(FractionTester, hasConstructorWhichInitialiseNumeratorAndDenominator)
{
    #if IMPLEMENTED_hasNumeratorAndDenominator
        static_assert (is_constructible_v<Fraction, int, int>, "Valid constructor not implemented!");

        struct FractionWrapper: public Fraction
        {
            using Fraction::numerator;
            using Fraction::denominator;
            using Fraction::Fraction;
        };

        constexpr int numberator = 3, denominator = 4;
        const FractionWrapper fraction(numberator, denominator);
        ASSERT_EQ(numberator,  fraction.numerator);
        ASSERT_EQ(denominator, fraction.denominator);
    #else
        ADD_FAILURE() << "Constructor not implemented!";
    #endif
}

TEST_F(FractionTester, hasGettersAndSetters)
{
    #if IMPLEMENTED_hasGettersAndSetters
        constexpr int numberator1 = 3, denominator1 = 4;
        Fraction fraction(numberator1, denominator1);
        ASSERT_EQ(numberator1,  fraction.getNumerator());
        ASSERT_EQ(denominator1, fraction.getDenominator());

        constexpr int numberator2 = 2, denominator2 = 1;
        fraction.setNumerator(numberator2);
        fraction.setDenominator(denominator2);

        ASSERT_EQ(numberator2,  fraction.getNumerator());
        ASSERT_EQ(denominator2, fraction.getDenominator());
    #else
        ADD_FAILURE() << "Class not implemented!";
    #endif
}

TEST_F(FractionTester, hasPrintFunction)
{
    #if IMPLEMENTED_hasPrintFunction
        constexpr int numerator = 3, denominator = 4;
        const Fraction fraction(numerator, denominator);

        CoutBufferSentinel coutSentinel;
        fraction.print();

        const string expectedOutput = to_string(numerator) + "/" + to_string(denominator) + "\n";

        ASSERT_EQ(expectedOutput, coutSentinel.getText());
    #else
        ADD_FAILURE() << "No function wypisz() implemented";
    #endif
}

TEST_F(FractionTester, counterOfDestructedFractionsImplemented)
{
    #if IMPLEMENTED_counterOfDestructedFractionsImplemented
        const auto removedFractions1 = Fraction::removedFractions();
        {
            Fraction fraction;
        }
        const auto removedFractions2 = Fraction::removedFractions();
        constexpr size_t expectedNumberOfRemovedFractionsInTheTest = 1;
        ASSERT_EQ(expectedNumberOfRemovedFractionsInTheTest, removedFractions2 - removedFractions1);
    #else
        ADD_FAILURE() << "No static function implemented";
    #endif
}

TEST_F(FractionTester, saveImplemented)
{
    #if IMPLEMENTED_readWriteImplemented
        constexpr int numerator = 3, denominator = 4;
        const Fraction fraction(numerator, denominator);
        ostringstream outputStream;
        fraction.save(outputStream);

        const string expectedOutput = to_string(numerator) + "/" + to_string(denominator);

        ASSERT_EQ(expectedOutput, outputStream.str());
    #else
        ADD_FAILURE() << "No static function implemented";
    #endif
}

TEST_F(FractionTester, loadImplemented)
{
    #if IMPLEMENTED_readWriteImplemented
        constexpr int numerator = 3, denominator = 4;

        Fraction fraction;

        const string expectedOutput = to_string(numerator) + "/" + to_string(denominator);

        istringstream inputStream(expectedOutput);
        fraction.load(inputStream);

        ASSERT_EQ(numerator, fraction.getNumerator());
        ASSERT_EQ(denominator, fraction.getDenominator());
    #else
        ADD_FAILURE() << "No static function implemented";
    #endif
}

TEST_F(FractionTester, fractionNameSettableFromConstructor)
{
    #if IMPLEMENTED_fractionNameSettableFromConstructor
        static_assert(is_constructible_v<Fraction, int, int, string>, "Constructor not implemented!");

        constexpr int numerator = 3, denominator = 4;
        const string fractionName("polowka");

        Fraction fraction(numerator, denominator, fractionName);

        ASSERT_EQ(numerator, fraction.getNumerator());
        ASSERT_EQ(denominator, fraction.getDenominator());
        ASSERT_EQ(fractionName, fraction.getFractionName());
    #else
        ADD_FAILURE() << "Function name not implemented!";
    #endif
}

TEST_F(FractionTester, fractionGettersAreConst)
{
    #if IMPLEMENTED_fractionNameSettableFromConstructor
        static_assert(is_constructible_v<Fraction, int, int, string>, "Constructor not implemented!");

        constexpr int numerator = 2, denominator = 4;
        const string fractionName("polowka");

        const Fraction fraction(numerator, denominator, fractionName);

        ASSERT_EQ(numerator, fraction.getNumerator());
        ASSERT_EQ(denominator, fraction.getDenominator());
        ASSERT_EQ(fractionName, fraction.getFractionName());
    #else
        ADD_FAILURE() << "Function name not implemented!";
    #endif
}

TEST_F(FractionTester, fractionConstStaticFieldsImplemented)
{
    #if IMPLEMENTED_fractionNameSettableFromConstructor
        static_assert(is_constructible_v<Fraction, int, int, string>, "Constructor not implemented!");
        constexpr int defaultDenominatorValue = 1, invalidDenominatorValue = 0;

        ASSERT_EQ(defaultDenominatorValue, Fraction::getDefaultDenominatorValue());
        ASSERT_EQ(invalidDenominatorValue, Fraction::getInvalidDenominatorValue());
    #else
        ADD_FAILURE() << "No static function implemented";
    #endif
}
