#include <algorithm>
#include <stdexcept>
#include <cstring>
#include "vector.h"

// constructor
Vector::Vector(size_t capacity) noexcept:
        data_(new Fraction[capacity]), size_(0), capacity_(capacity) {
}

Vector::Vector(const Vector &other) noexcept: data_(new Fraction[other.capacity()]), size_(other.size()),
                                              capacity_(other.capacity()) {
    std::memcpy(data_, other.data(), size_ * sizeof(Fraction));
}

Vector::Vector(Vector &&other) noexcept: data_(other.data()), size_(other.size()),
                                         capacity_(other.capacity()) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

// destructor
Vector::~Vector() {
    delete[] data_;
    size_ = 0;
    capacity_ = 0;
}

// getters
std::size_t Vector::size() const noexcept {
    return size_;
}

std::size_t Vector::capacity() const noexcept {
    return capacity_;
}

Fraction *Vector::data() const noexcept {
    return data_;
}

// operator= copying and moving
Vector &Vector::operator=(const Vector &other) noexcept {
    if (this == &other)
        return *this;
    data_ = new Fraction[other.capacity()];
    capacity_ = other.capacity();
    size_ = other.size();
    std::memcpy(data_, other.data(), size_ * sizeof(Fraction));
    return *this;
}

Vector &Vector::operator=(Vector &&other) noexcept {
    if (this != &other) {
        delete[] data_;

        data_ = other.data();
        size_ = other.size();
        capacity_ = other.capacity();

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

// push back
void Vector::push_back(const Fraction &fraction) noexcept {
    if (size_ == capacity_) {
        Fraction *new_data = new Fraction[capacity_++];
        std::copy(data_, data_ + 1, new_data);
        delete[] data_;
        data_ = new_data;
    }
    data_[size_] = fraction;
    size_++;
}

// operator[]
Fraction &Vector::operator[](std::size_t index) const {
    if (size_ <= index)
        throw std::out_of_range("Element out of range");
    return data_[index];
}

Fraction &Vector::operator[](std::size_t index) {
    if (size_ <= index)
        throw std::out_of_range("Element out of range");
    return data_[index];;
}