# Szablony klas i szablony funkcji

________________________________

## Zadanie implementacyjne:

1. Prosze utworzyć plik mylist.h, oraz dokonac nastepujacej implementacji:
   Proszę o zaimplementowanie szablonu klasy `MyList<T>`, reprezentujacej liste jednokierunkowa z glowa i iteratorami.
   Punktacja przydzielana za nastepujace metody (jak testy):
    1. za konstruktor bezargumentowy i metode `size()` zwracajaca ilosc elementow
    2. za metody `push_front` i `pop_front`, ktore odpowiednio dodaja/usuwaja element z poczatku
    3. metode `front()` zwracajaca element na poczatku, oraz aby `pop_front()` zwracala usuniety element. @note
       Standardowo w `std::list` metoda `pop_front()` nic nie zwraca. Jak myślisz - dlaczego?
    4. jesli pierwszy wezel (o nazwie head), oraz kazdy nastepny wezel (head->next)
       sa zaimplementowane przy pomocy `std::unique_ptr<MyList::Node>`
    5. jesli w razie zawolania `pop_front` na pustej liscie zostaje wyrzucony wyjatek `std::out_of_range`
    6. jesli kopiowanie (konstruktor kopiujacy i operator przypisania) jest niemozliwe dla listy
    7. jesli mamy zaimplementowane metody iteratora
       (tutaj jeszcze nie musza w pelni dzialac, chociaz powinny zwracac co nalezy)
    8. jesli napisany iterator dziala z petla for-zakresowym
    9. jesli nasz iterator dziala z algorytmami standardowymi na przykladzie `std::count_if`
       @note Do tego wymagane jest kilka aliasów typów.
    10. jesli mamy metode `remove(T element)`, ktora usuwa wszystkie elementy z listy o danej wartosci
    11. jesli lista ma operator wypisywania na strumien
        (forma wydruku dowolna, byleby byly wszystkie elementy)
2. Prosze o utworzenie pliku mySorting.h, W nim prosze o zaimplementowanie szablonu funkcji
   globalnej `void mySort(???)`:
   Punktacja (analogicznie jak testy):
    1. Sortowanie statycznej tablicy dziala
    2. Dziala z kontenerami standardowymi (na przykladzie `std::vector`)
    3. Dziala z nasza lista - specjalizacja
    4. Specjalizacja sortowania dla tablicy `char[][]`
       jesli dziala dla tablicy slów skladajacych sie wylacznie z DUZYCH LITER
    5. Jw. ale powinno dzialac z pominieciem wielkosci liter.
3. Tym razem kod ma się kompilować z flagami:
   `-Wall -Wextra -pedantic -Werror`
   dla hardcorów jeszcze:  `-Weffc++`

______________

## Uwaga:

1. Konieczne może się okazać zrobienie dwóch wersji metod begin/end -jedna stała, druga nie.
2. Należy zdefiniować dwie wersje iteratorów - stały `const_iterator` i zwykły `iterator` jako klasy zagnieżdżone.
   Najprościej jest dziedziczyć po `std::iterator`, niemniej jednak jest to deprecated.
3. Szablony muszą być zdefiniowane w całości w pliku nagłówkowym, jednakże proszę aby definicje metod dłuższych niż
   1-linijkowe były pod klasą.
4. Można użyć `std::sort` lub `std::stable_sort` - tylko trzeba wiedzieć gdzie i jak.