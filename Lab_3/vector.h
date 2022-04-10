#ifndef VECTOR_H
#define VECTOR_H


/** @file vector.h
 *  @brief Klasy Vector zarzadzająca dynamiczną tablicą na elementy i rozszerzająca się wg potrzeb z obsługą wyjątków.
 *  @note **UWAGA: To bardzo wazne zadanie, jeśli ktoś chce być programista C++ to w srodku nocy powinien umiec takie zadania robic!**
 *  @note Nasza implementacja wzorowana C++owym [std::vector](http://www.cplusplus.com/reference/vector/vector/), ale wystepuja różnice.
 *  @note Nie wolno uzyc w srodku std::vector! Zaawansowani moga uzyc uzyc inteligetnych wskaznikow, jesli chca.
## Tresc zadania:
1. Proszę aby klasa miała następujące składowe:
    - `Fraction* data_` - dynamiczna tablica na dane.
      **Osobom zaawansowanym sugeruję użyć inteligętnych wskaźników np. `std::unique_ptr<Fraction[]> data_`**
    - `std::size_t size_` - aktualna ilość elementów na tablicy
    - `std::size_t capacity_` - ile elementow pomieści aktualnie zaalokowana tablica.
2. Proszę o zaimplementowanie metod - getterów zwracających powyższe składowe - `size()`, `capacity()`, `data()`.
3. Proszę o zaimplementowanie konstuktora przyjmującego liczbę do wstępnej allokacji (z wartoscia domyslna 0)
4. Proszę o zaimplementowanie destruktora. Musi on koniecznie zwalniać pamięć
   (chyba, że używamy inteligętnych wskaźników, wtedy się zwolni automatycznie i nie musimy go implementować).
5. Proszę o zdefiniowanie konstuktora kopiującego, który będzie wykonywał tzw. "głęboką kopię"
   (czyli allokował nową pamięć i kopiował zawartość).
   **Osoby zaawansowane mogą to rozwiązać przez copy-on-write.**
6. Proszę o zdefiniowanie `operator=` wersji kopiującej głęboko i przenoszącej
7. Proszę zdefiniować metodę dodającą obiekt na koncu tablicy `push_back()`.
   **W razie braku miejsca metoda ta powinna dokonać reallokacji pamięci aby nowy element się zmieścił.**
8. Proszę o zdefiniowanie operatora indeksowania: `operator[](std::size_t index)` zwracający wskazany element tablicy.
   **Dostep po indeksie poza rozmiar tablicy (size) powinny być zgłaszane poprzez wyjątki `std::out_of_range`**
   @note Proszę pamiętać, że należy zdefiniować dwie wersje tego operatora - constową i zwykłą.

____________________________________________________________________________________
## Uwaga:
Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne, metody większe niż 1-linijkowe powinny być
 zadeklarowane w klasie, zdefiniowane poza klasą, obiekty typów klasowych powinny być w miarę możliwości przekazywane
 w argumentach funkcji przez referencję, proszę też stosować słówko "const" w odpowiednich miejscach.
____________________________________________________________________________________
## Podpowiedzi:
    - polecam uzycie operatora :?
    - mozna allokowac zero elementor: new int[0];
    - dla wygody mozna zastosowac idiom: [copy&swap](https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom),
      podkreslam jednak, ze jest to mniej wydajne
 **/

/** ----------------- ***********************

Nasza implementacja w razie automatycznego zwiekszania rozmiaru ma allokowac pamiec tylko o 1 wieksza!

    Deklaracje klasy powinny znaleźć się w odpowiednich plikach nagłówkowych, definicje metod i konstruktorów - w plikach źródłowych.
    Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne, metody/konstruktory/destruktory większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane poza klasą,

    Obiekty typów klasowych powinny być przekazywane do funkcji/metod przez referencje (zwykłe lub stałe), metody niemodyfikujące zawartości klasy powinny być oznaczane jako const.
    Wszystkie metody, które mogą być stałe proszę aby były
**/

#include <cstddef>
#include "fraction.h"


class Vector {
private:
    Fraction *data_;
    std::size_t size_, capacity_;

public:
    // constructor
    explicit Vector(std::size_t capacity = 0) noexcept;

    Vector(const Vector &other) noexcept;

    Vector(Vector &&other) noexcept;

    // destructor
    ~Vector();

    // getters
    [[nodiscard]] std::size_t size() const noexcept;

    [[nodiscard]] std::size_t capacity() const noexcept;

    [[nodiscard]] Fraction *data() const noexcept;

    // operator= copying and moving
    Vector &operator=(const Vector &other) noexcept;

    Vector &operator=(Vector &&other) noexcept;

    // push_back
    void push_back(const Fraction &fraction) noexcept;

    // operator[]
    Fraction &operator[](std::size_t index) const;

    Fraction &operator[](std::size_t index);
};

#endif // VECTOR_H