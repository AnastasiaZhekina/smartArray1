﻿#include <iostream>

#include <stdexcept>

class smart_array {

private:

    int* data;
    int size;
    int capacity;

public:

    smart_array(int s);

    void add_element(int element);

    int get_element(int index);

    ~smart_array();
};

int main() {

    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}

smart_array::smart_array(int s) : size(0), capacity(s) {
    data = new int[capacity];
};
void smart_array::add_element(int element) {
    if (size == capacity) {
        throw std::out_of_range("Array is full");
    }
    data[size++] = element;
};
int smart_array::get_element(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
};
smart_array::~smart_array() {
    delete[] data;
};