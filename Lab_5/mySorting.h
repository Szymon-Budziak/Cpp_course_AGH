#ifndef MYSORTING_H
#define MYSORTING_H

#include "myList.h"

template<typename T=int, typename S>
void mySort(S &array) {
    int len = std::size(array);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template<typename T>
void mySort(MyList<T> &array) {
    int len = array.size();
    if (len <= 1)
        return;
    for (auto i = array.begin(); i != array.end(); i++) {
        auto val = i;
        for (auto j = i; j != array.end(); j++) {
            if (*j < *val) {
                val = j;
            }
        }
        std::swap(*i, *val);
    }
}

template<int size1, int size2>
void mySort(char (&array)[size1][size2]) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size1 - 1; j++) {
            char str1[size2], str2[size2];
            snprintf(str1, size1 + 1, "%s", array[j]);
            snprintf(str2, size1 + 1, "%s", array[j + 1]);
            for (int k = 0; k < size2 + 1; k++) {
                str1[k] = toupper(str1[k]);
                str2[k] = toupper(str2[k]);
            }
            if (strcmp(str1, str2) > 0) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

#endif // MYSORTING_H