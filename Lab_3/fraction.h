#ifndef FRACTION_H
#define FRACTION_H


/** @file fraction.h
 *  @brief Bardziej zlozona implementacja klasy Fraction (Ulamek):
1. Klasa powinna posiadac pola `numerator_` (licznik) i `denominator_` (mianownik).
   Najlepiej aby byly to zmienne calkowite.
2. Powinna zawierac jeden konstruktor ustawiajacy licznik (domyslnie na 0)
   i mianownik (domyslne na 1)
3. Gettery i settery do wartosci licznika i mianownika m.in.: `denominator()` i `setDenominator(...)`.
    - Prosze pamietac, ze gettery, jako metody nic nie zmieniajace powinny byc oznaczone jako metody stale.
    - W mysl zasady aby w razie potrzeby kod modyfikowac w mniejszej ilosci miejsc sugeruje aby
      typem zwracanym getterow bylo `auto`.
4. `operator+` dla ulamka zwracajacy ulamek przez kopie. Metoda stala.
5. `operator*` dla ulamka zwracajacy ulamek przez kopie. Metoda stala.
6. Niepoprawny mianownik (=0) powinien byc zglaszany przez wyjatek `std::invalid_argument`.
   Dotyczy to wszystkich miejsc, gdzie jest ustawiany mianownik.
7. Prosze o automatyczne skracanie ulamkow po operacji + i *
   Pomocny moze sie okazac algorytm euklidesa, oczywiscie tutaj robimy tylko dla przypadkow dodatnich.
   Zachecam do uzycia `std::gcd(...)`.
____________________________________________________________________________________
Gettery i settery operujace na liczbach, ktore nie rzucaja wyjatku, warto zadeklarowac jako `noexcept`.
**/

class Fraction {
private:
    int numerator_, denominator_;

public:
    // constructor
    explicit Fraction(int numerator_ = 0, int denominator_ = 1);

    // getters
    [[nodiscard]] int numerator() const noexcept;

    [[nodiscard]] int denominator() const noexcept;

    // setters
    void setNumerator(int numerator) noexcept;

    void setDenominator(int denominator);

    // operator +
    Fraction operator+(const Fraction &other) const;

    // operator *
    Fraction operator*(const Fraction &other) const;

    // simplify fraction
    static Fraction simplifyFraction(Fraction fraction);
};

#endif // FRACTION_H
