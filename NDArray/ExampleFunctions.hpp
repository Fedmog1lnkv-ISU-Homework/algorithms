void defaultConstructor()
{
    std::cout << "Конструктор по умолчанию создает пустой массив заданного размера: 3x3" << std::endl;
    NDArray<int> arr({3, 3});
    std::cout << arr << std::endl;
}

void zerosExample()
{
    std::cout << "Создание массива заполненного нулями 2x4" << std::endl;
    auto arr = NDArray<int>::zeros({2, 4});
    std::cout << arr << std::endl;
}

void onesExample()
{
    std::cout << "Создание массива заполненного единицами 4x2" << std::endl;
    auto arr = NDArray<int>::ones({4, 2});
    std::cout << arr << std::endl;
}

void randomIntExample()
{
    std::cout << "Создание массива заполненного случайными int значениями" << std::endl;
    auto arr = NDArray<int>::random({2, 4});
    std::cout << arr << std::endl;
}

void randomFloatExample()
{
    std::cout << "Создание массива заполненного случайными float значениями" << std::endl;
    auto arr = NDArray<float>::random({2, 4});
    std::cout << arr << std::endl;
}

void additionOperator()
{
    std::cout << "Оператор поэлементного сложения" << std::endl;
    auto arr1 = NDArray<int>::ones({2, 4});
    auto arr2 = NDArray<int>::random({2, 4});
    auto arr3 = arr1 + arr2;
    std::cout << arr1 << std::endl;
    std::cout << "+\n"
              << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n"
              << std::endl;
    std::cout << arr3 << std::endl;
}

void subtractionOperator()
{
    std::cout << "Оператор поэлементного вычитания" << std::endl;
    auto arr1 = NDArray<int>::ones({2, 4});
    auto arr2 = NDArray<int>::random({2, 4});
    auto arr3 = arr1 - arr2;
    std::cout << arr1 << std::endl;
    std::cout << "-\n"
              << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n"
              << std::endl;
    std::cout << arr3 << std::endl;
}

void multiplicationOperator()
{
    std::cout << "Оператор поэлементного умножения" << std::endl;
    auto arr1 = NDArray<int>::ones({2, 3});
    auto arr2 = NDArray<int>::ones({2, 3});
    auto arr3 = arr1 * arr2;
    std::cout << arr1 << std::endl;
    std::cout << "*\n"
              << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n"
              << std::endl;
    std::cout << arr3 << std::endl;
}

void divisionOperator()
{
    std::cout << "Оператор поэлементного деления" << std::endl;
    auto arr1 = NDArray<int>::random({2, 4});
    auto arr2 = NDArray<int>::ones({2, 4});
    auto arr3 = arr1 / arr2;
    std::cout << arr1 << std::endl;
    std::cout << "/\n"
              << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n"
              << std::endl;
    std::cout << arr3 << std::endl;
}

void matmulExample()
{
    std::cout << "Метод матричного умножения" << std::endl;
    auto arr1 = NDArray<int>::random({2, 3});
    auto arr2 = NDArray<int>::random({3, 2});
    auto arr3 = arr1.matmul(arr2);
    std::cout << arr1 << std::endl;
    std::cout << "matmul\n"
              << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n"
              << std::endl;
    std::cout << arr3 << std::endl;
}

void transposeExample()
{
    std::cout << "Метод транспонирования матрицы" << std::endl;
    auto arr1 = NDArray<int>::random({2, 4});
    auto arr2 = arr1.transpose();
    std::cout << arr1 << std::endl;
    std::cout << arr2 << std::endl;
}

void getArrayElement()
{
    std::cout << "Метод для доступа к элементам массива" << std::endl;
    auto arr = NDArray<int>::random({2, 3});
    float element = arr[{0, 1}];
    std::cout << element << "\n"
              << std::endl;
}

void setArrayElement()
{
    std::cout << "Метод для изменения элементов массива" << std::endl;
    auto arr = NDArray<int>::random({2, 3});
    arr[{1, 2}] = 5.0;
    std::cout << arr << std::endl;
}

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void findMinFullArray()
{
    auto arr = NDArray<int>::random({3, 4});
    auto min_val = arr.min();
    std::cout << arr << std::endl
              << "Минимальное во всём массиве: ";
    print_vector(min_val);
    std::cout << std::endl;
}

void findMaxColumns()
{
    auto arr = NDArray<int>::random({3, 4});
    auto max_val = arr.max(0);
    std::cout << arr << std::endl
              << "Максимальные в каждом столбце: ";
    print_vector(max_val);
    std::cout << std::endl;
}

void findMeanRows()
{
    auto arr = NDArray<int>::random({3, 4});
    auto mean_val = arr.mean(1);
    std::cout << arr << std::endl
              << "Среднее в каждой строке: ";
    print_vector(mean_val);
    std::cout << std::endl;
}