#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

class MyString {
private:
    std::string string_text;
    size_t string_size;
    size_t string_capacity;
public:
    static const int initialBufferSize = 20;

    // MyString constructor
    MyString() : string_text(std::string()), string_size(string_text.size()),
                 string_capacity(initialBufferSize + string_text.capacity()) { string_text.reserve(initialBufferSize); }

    MyString(const char text[]) : string_text(text), string_size(string_text.size()),
                                  string_capacity(initialBufferSize + string_text.capacity()) {
        string_text.reserve(initialBufferSize);
    }

    explicit MyString(const std::string &text) : string_text(text), string_size(text.length()),
                                                 string_capacity(text.capacity()) {}

    // begin
    [[nodiscard]] std::string::const_iterator begin() const { return string_text.begin(); }

    // capacity
    [[nodiscard]] size_t capacity() const { return string_capacity; }

    // empty
    [[nodiscard]] bool empty() const { return string_size == 0; }

    // end
    [[nodiscard]] std::string::const_iterator end() const { return string_text.end(); }

    // operator !=
    bool operator!=(const MyString &) const;

    // operator <
    bool operator<(const MyString &string) const { return string_text.compare(string.string_text) < 0; }

    // operator +=
    MyString &operator+=(char);

    // operator ==
    bool operator==(const MyString &string) const { return string_text == string.string_text; }

    // operator []
    char operator[](size_t) const;

    // operator <<
    friend std::ostream &operator<<(std::ostream &, const MyString &);

    // operator >>
    friend std::istream &operator>>(std::istream &, MyString &);

    // size
    [[nodiscard]] size_t size() const { return string_size; }

    // all_of
    bool all_of(int predicate(int)) const;

    // join
    [[nodiscard]] MyString join(const std::vector<MyString> &) const;

    // generateRandomChar
    static char generateRandomChar() { return rand() % 26 + 65 + rand() % 2 * 32; }

    // generateRandomWord
    static MyString generateRandomWord(size_t);

    // getUniqueWords
    [[nodiscard]] std::set<MyString> getUniqueWords() const;

    // countWordsUsageIgnoringCases
    [[nodiscard]] std::map<MyString, size_t> countWordsUsageIgnoringCases() const;

    // startsWith
    [[nodiscard]] bool startsWith(std::string) const;

    // endsWith
    [[nodiscard]] bool endsWith(std::string) const;

    // toLower
    void toLower();

    // trim
    void trim();

    // clear
    void clear();
};

#endif // MYSTRING_H