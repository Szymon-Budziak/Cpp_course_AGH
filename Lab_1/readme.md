# Zaimplementuj podaną na zajęciach klasę reprezentującą ulamek:

1. Nazwa klasy Fraction, po której zdefiniowaniu zmień: w makrze
   `IMPLEMENTED_classFractionExists 0` -> `IMPLEMENTED_classFractionExists 1`
2. Do klasy dodaj pola protected:
   `numerator` (licznik) i `denominator` (mianownik)
   następnie ustaw jedynkę obok `IMPLEMENTED_hasNumeratorAndDenominator`
3. Do klasy dodaj konstruktor bezparametrowy (może być też z wartościami domyślnymi), który ustawi wartości licznika na
   0 i mianownika na 1 następnie ustaw jedynkę obok `IMPLEMENTED_hasDefaultConstructor`
4. Do klasy dodaj konstruktor z parametrami (może być modyfikacja powyższego), który ustawi licznik i mianownik na
   podstawie parametrów, a) wartością domyślną dla mianownika ma być 1 następnie ustaw jedynkę
   obok `IMPLEMENTED_hasConstructorWhichInitialiseFields`
5. Do klasy dodaj zestaw metod dostępowych/modyfikujących obiekty klasy -tzw. gettery i settery, które umożliwią
   modyfikacje i pobranie wartości licznika i mianownika następnie ustaw jedynkę obok `IMPLEMENTED_hasGettersAndSetters`
6. Do klasy dodaj metodę print(), wypisującą atrybuty obiektu na konsolę w formie "licznik/mianownik\n"
   następnie ustaw jedynkę obok `IMPLEMENTED_hasPrintFunction`
7. Do klasy dodaj statyczny atrybut (removedFractions_)
   i metodę statyczną: removedFractions() zwracającą ten atrybut Skladowa ta powinna byc incrementowana w destruktorze
   następnie ustaw jedynkę obok `IMPLEMENTED_counterOfDestructedFractionsImplemented`
8. Dodaj do klasy metody zapisz(std::ostream& os)/wczytaj(std::istream& is), zapisujące/odczytujące zawartość obiektu do
   przekazanego jako parametr strumienia wyjściowego/wejściowego, w formacie "licznik/mianownik". Metoda wczytująca może
   założyć, że format danych będzie poprawny
   (nie trzeba obslugiwac bledow). następnie ustaw jedynkę obok `IMPLEMENTED_readWriteImplemented`.
9. Proszę dodanie stałej odzwierciedlającej nazwę ułamka o nazwie `fractionName`, powinna być protected. Do niej proszę
   dodać metodę stałą:
   `getFractionName()`
   następnie ustaw jedynkę obok `IMPLEMENTED_fractionNameSettableFromConstructor`
10. Do klasy dodaj dwie stałe:
    a) stała statyczna odzwierciedlajaca niedopuszczalna wartość mianownika: `invalidDenominatorValue`
    b) metodę statyczną zwracającą powyższe: `getInvalidDenominatorValue()`
    c) stałą statyczną czasu kompilacji (constexpr) odzwierciedlajaca domyślna wartość
    mianownika: `defaultDenominatorValue`
    d) metodę constexpr `getDefaultDenominatorValue()` zwracającą powyższe następnie ustaw jedynkę
    obok `IMPLEMENTED_fractionConstStaticFieldsImplemented`
