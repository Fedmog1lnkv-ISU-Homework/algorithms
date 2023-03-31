NDArray defaultConstructor()
{
    std::cout<<"Конструктор по умолчанию создает пустой массив заданного размера: 3x3"<<std::endl;
    NDArray arr({3, 3});
    std::cout << arr << std::endl;
    return arr;
}

NDArray zerosExample()
{
    std::cout<<"Создание массива заполненного нулями 2x4"<<std::endl;
    auto arr = NDArray::zeros({2, 4});
    std::cout << arr << std::endl;
    return arr;
}

NDArray onesExample()
{
    std::cout<<"Создание массива заполненного единицами 4x2"<<std::endl;
    auto arr = NDArray::ones({4, 2});
    std::cout << arr << std::endl;
    return arr;
}

NDArray randomExample()
{
    std::cout<<"Создание массива заполненного случайными значениями"<<std::endl;
    auto arr = NDArray::random({2, 4});
    std::cout << arr << std::endl;
    return arr;
}

NDArray additionOperator()
{
    std::cout<<"Оператор поэлементного сложения"<<std::endl;
    auto arr1 = NDArray::ones({2, 4});
    auto arr2 = NDArray::random({2, 4});
    auto arr3 = arr1 + arr2;
    std::cout << arr1 << std::endl;
    std::cout << "+\n" << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n" << std::endl;
    std::cout << arr3 << std::endl;
    return arr3;
}

NDArray subtractionOperator()
{
    std::cout<<"Оператор поэлементного вычитания"<<std::endl;
    auto arr1 = NDArray::ones({2, 4});
    auto arr2 = NDArray::random({2, 4});
    auto arr3 = arr1 - arr2;
    std::cout << arr1 << std::endl;
    std::cout << "-\n" << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n" << std::endl;
    std::cout << arr3 << std::endl;
    return arr3;
}

NDArray multiplicationOperator()
{
    std::cout<<"Оператор поэлементного умножения"<<std::endl;
    auto arr1 = NDArray::ones({2, 3});
    auto arr2 = NDArray::ones({2, 3});
    auto arr3 = arr1 * arr2;
    std::cout << arr1 << std::endl;
    std::cout << "*\n" << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n" << std::endl;
    std::cout << arr3 << std::endl;
    return arr3;
}

NDArray divisionOperator()
{
    std::cout<<"Оператор поэлементного деления"<<std::endl;
    auto arr1 = NDArray::random({2, 4});
    auto arr2 = NDArray::ones({2, 4});
    auto arr3 = arr1 / arr2;
    std::cout << arr1 << std::endl;
    std::cout << "/\n" << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n" << std::endl;
    std::cout << arr3 << std::endl;
    return arr3;
}

NDArray matmulExample()
{
    std::cout<<"Метод матричного умножения"<<std::endl;
    auto arr1 = NDArray::random({2, 3});
    auto arr2 = NDArray::random({3, 2});
    auto arr3 = arr1.matmul(arr2);
    std::cout << arr1 << std::endl;
    std::cout << "matmul\n" << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << "=\n" << std::endl;
    std::cout << arr3 << std::endl;
    return arr3;
}

NDArray transposeExample()
{
    std::cout<<"Метод транспонирования матрицы"<<std::endl;
    auto arr1 = NDArray::random({2, 4});
    auto arr2 = arr1.transpose();
    std::cout << arr1 << std::endl;
    std::cout << arr2 << std::endl;
    return arr2;
}

float getArrayElement()
{
    std::cout<<"Метод для доступа к элементам массива"<<std::endl;
    auto arr = NDArray::random({2, 3});
    float element = arr[{0, 1}];
    std::cout << element << "\n" <<std::endl;
    return element;
}

NDArray setArrayElement()
{
    std::cout<<"Метод для изменения элементов массива"<<std::endl;
    auto arr = NDArray::random({2, 3});
    arr[{1, 2}] = 5.0;
    std::cout << arr << std::endl;
    return arr;
}
