#include "NDArray.h"

NDArray::NDArray(std::vector<int> shape)
{
    this->shape = shape;
    this->size = std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int>());
    data = std::vector<float>(size);
}

NDArray NDArray::zeros(std::vector<int> shape)
{
    NDArray arr(shape);
    return arr;
}

NDArray NDArray::ones(std::vector<int> shape)
{
    NDArray arr(shape);
    std::fill(arr.data.begin(), arr.data.end(), 1);
    return arr;
}

NDArray NDArray::random(std::vector<int> shape)
{
    NDArray arr(shape);
    std::srand((unsigned)std::time(nullptr));
    for (int i = 0; i < arr.size; i++)
    {
        arr.data[i] = (float)std::rand() / RAND_MAX;
    }
    return arr;
}

float &NDArray::operator[](std::vector<int> indices)
{
    int idx = 0;
    for (int i = 0; i < static_cast<int>(indices.size()); i++)
    {
        idx += indices[i] * std::accumulate(shape.begin() + i + 1, shape.end(), 1, std::multiplies<int>());
    }
    return data[idx];
}

const float &NDArray::operator[](std::vector<int> indices) const
{
    int idx = 0;
    for (int i = 0; i < static_cast<int>(indices.size()); i++)
    {
        idx += indices[i] * std::accumulate(shape.begin() + i + 1, shape.end(), 1, std::multiplies<int>());
    }
    return data[idx];
}

std::ostream &operator<<(std::ostream &os, const NDArray &arr)
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

NDArray NDArray::operator+(const NDArray &other)
{
    if (shape != other.shape)
        throw std::invalid_argument("Dimensions don't match");
    NDArray res(shape);
    for (int i = 0; i < size; ++i)
    {
        res.data[i] = data[i] + other.data[i];
    }
    return res;
}

NDArray NDArray::operator-(const NDArray &other)
{
    if (shape != other.shape)
        throw std::invalid_argument("Dimensions don't match");
    NDArray res(shape);
    for (int i = 0; i < size; ++i)
    {
        res.data[i] = data[i] - other.data[i];
    }
    return res;
}

NDArray NDArray::operator*(const NDArray &other)
{
    if (shape != other.shape)
        throw std::invalid_argument("Dimensions don't match");
    NDArray res(shape);
    for (int i = 0; i < size; ++i)
    {
        res.data[i] = data[i] * other.data[i];
    }
    return res;
}

NDArray NDArray::operator/(const NDArray &other)
{
    if (shape != other.shape)
        throw std::invalid_argument("Dimensions don't match");
    NDArray res(shape);
    for (int i = 0; i < size; ++i)
    {
        if (other.data[i] == 0)
            throw std::invalid_argument("Division by zero");
        res.data[i] = data[i] / other.data[i];
    }
    return res;
}

NDArray NDArray::matmul(const NDArray &other)
{
    if (shape.size() != 2 || other.shape.size() != 2 || shape[1] != other.shape[0])
    {
        throw std::invalid_argument("Incompatible shapes for matrix multiplication");
    }

    std::vector<int> out_shape = {shape[0], other.shape[1]};
    NDArray out = NDArray::zeros(out_shape);

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

NDArray NDArray::transpose()
{
    if (shape.size() != 2)
    {
        throw std::invalid_argument("Can only transpose 2-dimensional arrays");
    }

    std::vector<int> transposed_shape = {shape[1], shape[0]};

    NDArray transposed_array = NDArray::zeros(transposed_shape);

    for (int i = 0; i < shape[0]; i++)
    {
        for (int j = 0; j < shape[1]; j++)
        {
            transposed_array[{j, i}] = (*this)[{i, j}];
        }
    }

    return transposed_array;
}
