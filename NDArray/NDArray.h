#ifndef NDARRAY_NDARRAY_H
#define NDARRAY_NDARRAY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
#include <utility>

class NDArray
{
private:
    std::vector<float> data;
    std::vector<int> shape;
    int size;

public:
    // Конструктор по умолчанию создает пустой массив заданного размера
    NDArray(std::vector<int> shape);

    // Создание массива заполненного нулями
    static NDArray zeros(std::vector<int> shape);

    // Создание массива заполненного единицами
    static NDArray ones(std::vector<int> shape);

    // Создание массива заполненного случайными значениями
    static NDArray random(std::vector<int> shape);

    // Оператор поэлементного сложения
    NDArray operator+(const NDArray &other);

    // Оператор поэлементного вычитания
    NDArray operator-(const NDArray &other);

    // Оператор поэлементного умножения
    NDArray operator*(const NDArray &other);

    // Оператор поэлементного деления
    NDArray operator/(const NDArray &other);

    // Метод матричного умножения
    NDArray matmul(const NDArray &other);

    // Метод транспонирования матрицы
    NDArray transpose();

    // Методы для доступа к элементам массива
    float &operator[](std::vector<int> indices);

    // Методы для доступа к элементам массива
    const float &operator[](std::vector<int> indices) const;

    friend std::ostream &operator<<(std::ostream &os, const NDArray &arr);
};

#endif // NDARRAY_NDARRAY_H
