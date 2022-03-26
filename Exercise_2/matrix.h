#ifndef MATRIX_H
#define MATRIX_H

/** matrix.h
Przeciążanie operatorów na przykładzie Macierzy:
1. Zaimplementuj klasę TwoDimensionMatrix odzwierciedlajaca macierz 2*2, zawierającą:
    - tablice typu MatrixElement (tzn. int), oraz size (=2)
    - konstruktory:
        - bezargumentowy - zerujący wszystkie elementy
        - kopiujący
        - przyjmujący jako argument tablicę (const MatrixElement matrix[size][size]) i kopiujący z niej wartości
    - funkcja składowa do dostępu do elementów (get() zwracająca odpowiedni element
    - funkcja zwracająca size o nazwie (getSize()), proponuję aby była static constexpr
2. Uzupełnij klasy o następujące operacje zdefiniowane poprzez przeciążenie operatorów:
    - operator przypisania kopiujący (głęboko): operator=()
    - operatory wypisywania do strumienia (funkcja zewn.) - forma dowolna, byleby wszystkie elementy były w strumieniu
    - operatory wczytywania z strumienia (funkcja zewn.) - format dla macierzy:
      { a, b }
      { c, d }
      powinno się odbyć:
      ```
        a b
        c d
      ```
    - operatory arytmetyczne (stosujące odpowiednie operacje na macierzach):
        - TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2); // jako funkcja globalna
        - TwoDimensionMatrix& operator*=(MatrixElement number); // metoda klasy
        - Zadany operator logiczny (metoda klasy):
          `TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;`
        - operator tablicowy dostający się po indeksie do pierwszego z wymiarów tablicy (metoda klasy), **proszę pamiętać o wersji const**
          `MatrixElement* operator[](size_t i);`
        - operator konwersji do size_t, zwracający to co `getSize()` (metoda klasy),
    Deklaracja klasy i funkcji globalnych powinna się znaleźć w pliku "matrix.h", natomiast definicje funkcji zewnętrznych i metod klas w pliku źródłowym "matrix.cpp"
**/

#include <iosfwd>
#include "matrixElement.h"

class TwoDimensionMatrix {
    constexpr static size_t size = 2;
    MatrixElement matrix[size][size];

public:
    // constructor
    TwoDimensionMatrix();

    TwoDimensionMatrix(const TwoDimensionMatrix &matrix);

    explicit TwoDimensionMatrix(const MatrixElement matrix[size][size]);

    // getter
    [[nodiscard]] MatrixElement get(size_t row, size_t column) const;

    static constexpr size_t getSize() { return size; }

    // operator =
    TwoDimensionMatrix &operator=(const TwoDimensionMatrix &matrix);

    // operator << (output)
    friend std::ostream &operator<<(std::ostream &output, const TwoDimensionMatrix &matrix);

    // operator >> (input)
    friend std::istream &operator>>(std::istream &input, TwoDimensionMatrix &matrix);

    // operator +
    friend TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2);

    // operator *=
    TwoDimensionMatrix &operator*=(MatrixElement number);

    // operator &&
    TwoDimensionMatrix operator&&(const TwoDimensionMatrix &matrix) const;

    // operator []
    MatrixElement *operator[](size_t i);

    const MatrixElement *operator[](size_t i) const;

    // operator size_t
    explicit operator size_t() const { return size; };
};

// operator <<
std::ostream &operator<<(std::ostream &output, const TwoDimensionMatrix &matrix);

// operator >>
std::istream &operator>>(std::istream &input, TwoDimensionMatrix &matrix);

// operator+
TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2);

#endif // MATRIX_H