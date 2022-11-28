#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
#pragma once
template<typename T>
class set_of_numbers
{

private:

    int size;
    int count;
    T* array;

public:

    ~set_of_numbers();

    int presence(const T& number) const;

    T& operator [] (const int& index) const;

    set_of_numbers(int size = 0);

    set_of_numbers(const set_of_numbers<T>& other_set);

    void operator = (const set_of_numbers<T>& other_set);

    void add(const T& number);

    void delete_(const T& number);

    set_of_numbers operator + (const set_of_numbers<T>& set_1);

    set_of_numbers operator - (const set_of_numbers<T>& set_1);

    void operator + (const T& number);

    void operator += (const T& number);

    void operator - (const T& number);

    void operator -= (const T& number);

    set_of_numbers intersection(const set_of_numbers<T>& set_2) const;

    bool operator == (const set_of_numbers<T>& set_2) const;

    bool operator != (const set_of_numbers<T>& set_2) const;

    bool occurrence_of_elements(const set_of_numbers<T>& set_2) const;

    friend ostream& operator << (ostream& os, const set_of_numbers<T>& set);

};

template class set_of_numbers<int>;
template class set_of_numbers<float>;
template class set_of_numbers<string>;
template class set_of_numbers<pair<int, double>>;