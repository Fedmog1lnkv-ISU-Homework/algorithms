#ifndef NDARRAY_NDARRAY_H
#define NDARRAY_NDARRAY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
#include <utility>

template <typename T>
class NDArray
{
private:
    std::vector<int> shape;
    int size;
    std::vector<T> data;

public:
    // Конструктор по умолчанию
    NDArray(std::vector<int> shape)
    {
        this->shape = shape;
        this->size = std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int>());
        data = std::vector<T>(size);
    }

    // Создание массива заполненного нулями
    static NDArray zeros(std::vector<int> shape)
    {
        NDArray arr(shape);
        return arr;
    }

    // Создание массива заполненного единицами
    static NDArray ones(std::vector<int> shape)
    {
        NDArray arr(shape);
        if constexpr (std::is_same_v<T, float>)
        {
            std::fill(arr.data.begin(), arr.data.end(), 1);
        }
        else if constexpr (std::is_same_v<T, int>)
        {
            std::fill(arr.data.begin(), arr.data.end(), 1);
        }
        return arr;
    }

    // Создание массива заполненного случайными значениями
    static NDArray random(std::vector<int> shape)
    {
        NDArray arr(shape);
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        for (int i = 0; i < arr.size; i++)
        {
            if constexpr (std::is_same_v<T, float>)
            {
                arr.data[i] = (float)std::rand() / RAND_MAX;
            }
            else if constexpr (std::is_same_v<T, int>)
            {
                arr.data[i] = std::rand();
            }
        }
        return arr;
    }

    // Методы для доступа к элементам массива
    T &operator[](std::vector<int> indices)
    {
        int idx = 0;
        for (int i = 0; i < static_cast<int>(indices.size()); i++)
        {
            idx += indices[i] * std::accumulate(shape.begin() + i + 1, shape.end(), 1, std::multiplies<int>());
        }
        return data[idx];
    }

    const T &operator[](std::vector<int> indices) const
    {
        int idx = 0;
        for (int i = 0; i < static_cast<int>(indices.size()); i++)
        {
            idx += indices[i] * std::accumulate(shape.begin() + i + 1, shape.end(), 1, std::multiplies<int>());
        }
        return data[idx];
    }

    // Оператор вывода
    friend std::ostream &operator<<(std::ostream &os, const NDArray<T> &arr)
    {
        std::vector<int> indices(arr.shape.size(), 0);
        for (int i = 0; i < arr.size; i++)
        {
            os << arr[indices] << " ";

            // Вычисляем индексы следующего элемента
            for (int j = arr.shape.size() - 1; j >= 0; j--)
            {
                indices[j]++;
                if (indices[j] < arr.shape[j])
                    break;
                indices[j] = 0;
            }
            if (i % arr.shape.back() == arr.shape.back() - 1)
                os << std::endl;
        }
        return os;
    }

    // Оператор поэлементного сложения
    NDArray<T> operator+(const NDArray<T> &other)
    {
        if (shape != other.shape)
            throw std::invalid_argument("Dimensions don't match");
        NDArray<T> res(shape);
        for (int i = 0; i < size; ++i)
        {
            res.data[i] = data[i] + other.data[i];
        }
        return res;
    }

    // Оператор поэлементного вычитания
    NDArray<T> operator-(const NDArray<T> &other)
    {
        if (shape != other.shape)
            throw std::invalid_argument("Dimensions don't match");
        NDArray<T> res(shape);
        for (int i = 0; i < size; ++i)
        {
            res.data[i] = data[i] - other.data[i];
        }
        return res;
    }

    // Оператор поэлементного умножения
    NDArray<T> operator*(const NDArray<T> &other)
    {
        if (shape != other.shape)
            throw std::invalid_argument("Dimensions don't match");
        NDArray<T> res(shape);
        for (int i = 0; i < size; ++i)
        {
            res.data[i] = data[i] * other.data[i];
        }
        return res;
    }

    // Оператор поэлементного деления
    NDArray<T> operator/(const NDArray<T> &other)
    {
        if (shape != other.shape)
            throw std::invalid_argument("Dimensions don't match");
        NDArray<T> res(shape);
        for (int i = 0; i < size; ++i)
        {
            if constexpr (std::is_same_v<T, float>)
            {
                if (other.data[i] == 0)
                    throw std::invalid_argument("Division by zero");
            }
            res.data[i] = data[i] / other.data[i];
        }
        return res;
    }

    // Метод матричного умножения
    NDArray<T> matmul(const NDArray<T> &other)
    {
        if (shape.size() != 2 || other.shape.size() != 2 || shape[1] != other.shape[0])
        {
            throw std::invalid_argument("Incompatible shapes for matrix multiplication");
        }

        std::vector<int> out_shape = {shape[0], other.shape[1]};
        NDArray<T> out = NDArray<T>::zeros(out_shape);

        for (int i = 0; i < out_shape[0]; i++)
        {
            for (int j = 0; j < out_shape[1]; j++)
            {
                float dot_product = 0;
                for (int k = 0; k < shape[1]; k++)
                {
                    dot_product += (*this)[{i, k}] * other[{k, j}];
                }
                out[{i, j}] = dot_product;
            }
        }

        return out;
    }

    // Метод транспонирования матрицы
    NDArray<T> transpose()
    {
        if (shape.size() != 2)
        {
            throw std::invalid_argument("Can only transpose 2-dimensional arrays");
        }

        std::vector<int> transposed_shape = {shape[1], shape[0]};

        NDArray<T> transposed_array = NDArray<T>::zeros(transposed_shape);

        for (int i = 0; i < shape[0]; i++)
        {
            for (int j = 0; j < shape[1]; j++)
            {
                transposed_array[{j, i}] = (*this)[{i, j}];
            }
        }

        return transposed_array;
    }
};

#endif // NDARRAY_NDARRAY_H
