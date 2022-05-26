# STL: MyString
------------------------

## Zadanie implementacyjne:

1. Wykorzystanie biblioteki STL i kontenerów podczas implementacji klasy MyString (ile testów przejdzie, tyle punktów)
2. Klasa ta ma zawierać statyczna tablice na tekst do 20 znaków, a resztę ma w razie potrzeby pobierać dynamicznie np.
   przy pomocy typu `std::string`.
3. Funkcjonalności są dopasowane tak, aby użyć kilku kontenerów standardowych, poćwiczyć pisanie iteratorów, oraz użyć
   algorytmów uogólnionych (`<algorithm>`).
4. Tresc nalezy wydedukowac w oparciu o plik z testami, nad wieloma testami jest sugestia czego można użyć.
5. Można też użyć biblioteki boost (oczywiście wtedy w razie błędów kompilacji na sprawdzarce proszę o maila z
   informacją czego Państwo używają).
6. Sygnatury funkcji do zaimplementowania (pobrane przy pomocy `ctags`):

   | metoda                | sygnatura                                                            |
               |----------------------	|--------------------------------------------------------------------	|
   | MyString               | MyString(const char *text)                                            |
   | MyString               | MyString(const MyString &text)                                        |
   | begin                    | iterator begin()                                                    |
   | begin                    | const_iterator begin() const                                        |
   | capacity                | auto capacity() const                                                |
   | cbegin                | const_iterator cbegin() const                                        |
   | cend                    | const_iterator cend() const                                            |
   | const_iterator        | explicit const_iterator(const MyString* myString, size_t position)    |
   | empty                    | bool empty() const                                                    |
   | end                    | iterator end()                                                        |
   | end                    | const_iterator end() const                                            |
   | getPosition            | auto getPosition() const                                            |
   | iterator                | explicit iterator(MyString* myString, size_t position)                |
   | operator !=            | bool operator!=(const MyString& rhs) const                            |
   | operator !=            | bool operator!=(iterator anotherIt)                                    |
   | operator !=            | bool operator!=(const_iterator anotherIt) const                        |
   | operator *           	| char& operator*()                                                    |
   | operator *           	| char operator*() const                                                |
   | operator +            | iterator operator+(size_t pos)                                        |
   | operator +            | const_iterator operator+(size_t pos) const                            |
   | operator ++            | iterator& operator++()                                                |
   | operator ++            | const_iterator& operator++()                                        |
   | operator -            | size_t operator-(iterator anotherIt)                                |
   | operator -            | size_t operator-(const_iterator anotherIt) const                    |
   | operator --            | iterator& operator--()                                                |
   | operator --            | const_iterator& operator--()                                        |
   | operator ==            | bool operator==(iterator anotherIt)                                    |
   | operator ==            | bool operator==(const_iterator anotherIt) const                        |
   | operator []            | char operator[](size_t i) const                                        |
   | operator std::string    | explicit operator std::string() const                                |
   | push_back                | void push_back(char c)                                                |
   | size                    | auto size() const                                                    |
   | map<MyString, size_t> | countWordsUsageIgnoringCases() const;                                  |
   | all_of                | bool all_of(std::function<bool(char)> predicate) const                 |
   | generateRandomWord    | static MyString generateRandomWord(size_t length)                      |
   | getUniqueWords        | std::set<MyString> getUniqueWords() const                              |
   | join                  | MyString join(const std::vector<MyString> &texts) const                | 
   | startsWith            | bool MyString::startsWith(const char *text) const                      |
   | toLower               | MyString& toLower()                                                    |
   | trim                  | MyString& trim()                                                       |

8. Tym razem kod ma się kompilować z flagami:
   `-Wall -Wextra -pedantic -Werror`
   dla hardcorów jeszcze:  `-Weffc++`

______________
Uwaga:
--------

1. Konieczne jest zrobienie dwóch wersji metod begin/end -jedna stała, druga nie. Podobnie dwóch wersji iteratora.
2. Informacje [jak zdefiniować własny iterator](https://medium.com/geekculture/iterator-design-pattern-in-c-42caec84bfc)
   lub [2](https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators).