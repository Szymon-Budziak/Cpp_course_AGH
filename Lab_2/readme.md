# Przeciążanie operatorów na przykładzie Macierzy:

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
      { a, b } { c, d } powinno się odbyć:
      ```
        a b
        c d
      ```
    - operatory arytmetyczne (stosujące odpowiednie operacje na macierzach):
        - TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2); // jako
          funkcja globalna
        - TwoDimensionMatrix& operator*=(MatrixElement number); // metoda klasy
        - Zadany operator logiczny (metoda klasy):
          `TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;`
        - operator tablicowy dostający się po indeksie do pierwszego z wymiarów tablicy (metoda klasy), **proszę
          pamiętać o wersji const**
          `MatrixElement* operator[](size_t i);`
        - operator konwersji do size_t, zwracający to co `getSize()` (metoda klasy), Deklaracja klasy i funkcji
          globalnych powinna się znaleźć w pliku "matrix.h", natomiast definicje funkcji zewnętrznych i metod klas w
          pliku źródłowym "matrix.cpp"