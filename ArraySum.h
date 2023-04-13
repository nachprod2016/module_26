#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>

class ArraySum
{
private:
    //размер массива
    size_t arrSize;
    //размер подмассива
    size_t sizeSubArrays;
    //количество подмассивов
    int subArrays;
    //сумма элементов массива
    int sumElements;
    //указатель на массив
    int * arr;
public:
    ArraySum(size_t, size_t);
    ~ArraySum();
    void showArrayElements();
    void calculate();
    int sum(size_t, size_t, size_t &);
    void showSumElements();
};