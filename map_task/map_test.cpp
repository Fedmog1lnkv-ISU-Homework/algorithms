#include <iostream>
#include <map>
#include <chrono>
#include <cstdlib>
#include <cmath>

int main()
{
    srand(time(0));
    size_t n_elements;
    int key, value;
    for (int i = 0; i <= 8; ++i)
    {
        std::map<int, int> test_map;
        auto start_time = std::chrono::high_resolution_clock::now();
        n_elements = pow(10, i);
        for (size_t j = 1; j <= n_elements; ++j)
        {
            key = std::rand();
            value = std::rand();
            test_map.insert(std::make_pair(key, value));
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto time_diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        // количество элементов - размер map - время заполнения в наносекундах
        std::cout << n_elements << " " << sizeof(test_map) + test_map.size() * n_elements << " " << time_diff.count() << std::endl;
    }
    return 0;
}