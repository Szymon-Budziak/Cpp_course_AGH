#include "mystring.h"

// operator!=
bool MyString::operator!=(const MyString &string) const {
    std::pair result = std::mismatch(string_text.begin(), string_text.end(), string.begin());
    if (result.first == string_text.begin() && string_text[0] == string[0])
        return false;
    return true;
}

// operator+=
MyString &MyString::operator+=(const char character) {
    string_text += character;
    string_size = string_text.size();
    string_capacity = string_text.capacity();
    return *this;
}

// operator[]
char MyString::operator[](size_t index) const {
    if (index >= string_size)
        throw std::out_of_range("Index out of range");
    return string_text[index];
}

// operator<<
std::ostream &operator<<(std::ostream &stream, const MyString &string) {
    return stream << string.string_text;
}

// operator>>
std::istream &operator>>(std::istream &stream, MyString &string) {
    std::string buffer;
    while (stream >> buffer) {
        string.string_text.append(buffer);
        string.string_text.append(" ");
    }
    string.string_capacity = string.string_text.capacity();
    string.string_size = string.string_text.size();
    return stream;
}

// all_of
bool MyString::all_of(int (*predicate)(int)) const {
    return std::all_of(string_text.begin(), string_text.end(), predicate);
}

// join
MyString MyString::join(const std::vector<MyString> &string) const {
    MyString text;
    for (auto &&element: string) {
        for (char c: element.string_text)
            text += c;
        for (char sep: string_text)
            text += sep;
    }
    for (int i = 0; i < string_text.size(); i++)
        text.string_text.pop_back();
    return text;
}

// generateRandomWord
MyString MyString::generateRandomWord(size_t length) {
    std::string word(length, ' ');
    std::generate_n(word.begin(), length, generateRandomChar);
    return MyString(word);
}

// getUniqueWords
std::set<MyString> MyString::getUniqueWords() const {
    std::set<MyString> unique_words;
    std::string string_copy = string_text;
    auto to_lower = [](char c) { return std::tolower(c); };
    auto is_space = [](char c) { return std::isspace(c); };
    std::transform(string_copy.begin(), string_copy.end(), string_copy.begin(), to_lower);
    auto i = string_copy.begin();
    auto j = string_copy.begin();
    while (i != string_copy.end()) {
        i = std::find_if_not(i, string_copy.end(), is_space);
        j = std::find_if(i, string_copy.end(), is_space);
        auto d1 = i - string_copy.begin();
        auto d2 = j - string_copy.begin();
        std::string word = string_copy.substr(d1, d2 - d1);
        unique_words.insert(MyString(word));
        i = j;
    }
    return unique_words;
}

// countWordsUsageIgnoringCases
std::map<MyString, size_t> MyString::countWordsUsageIgnoringCases() const {
    std::map<MyString, size_t> word_usage;
    auto is_space = [](char c) { return std::isspace(c); };
    auto i = string_text.begin();
    auto j = string_text.begin();
    while (i != string_text.end()) {
        i = std::find_if_not(i, string_text.end(), is_space);
        j = std::find_if(i, string_text.end(), is_space);

        auto d1 = i - string_text.begin();
        auto d2 = j - string_text.begin();
        std::string word = string_text.substr(d1, d2 - d1);
        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !std::isalpha(c); }), word.end());
        MyString my_string_word(word);

        if (word_usage.find(my_string_word) == word_usage.end())
            word_usage.insert(std::pair<MyString, size_t>(my_string_word, 1));
        else
            word_usage.find(my_string_word)->second++;
        i = j;
    }
    return word_usage;
}

// startsWith
bool MyString::startsWith(std::string string) const {
    auto start = std::search(string_text.begin(), string_text.end(), string.begin(), string.end());
    return start == string_text.begin();
}

// endsWith
bool MyString::endsWith(std::string string) const {
    auto start = std::search(string_text.begin(), string_text.end(), string.begin(), string.end());
    return start == string_text.end() - string.size();
}

// toLower
void MyString::toLower() {
    auto to_lower = [](char c) { return std::tolower(c); };
    std::transform(string_text.begin(), string_text.end(), string_text.begin(), to_lower);
}

// trim
void MyString::trim() {
    auto left = std::find_if_not(string_text.begin(), string_text.end(),
                                 [](unsigned char c) { return std::isspace(c); });
    auto right = std::find_if_not(string_text.rbegin(), string_text.rend(),
                                  [](unsigned char c) { return std::isspace(c); }).base();
    string_text = std::string(left, right);
    string_size = string_text.size();
    string_capacity = string_text.capacity();
}

// clear
void MyString::clear() {
    string_text.clear();
    string_size = 0;
    string_capacity = 0;
}