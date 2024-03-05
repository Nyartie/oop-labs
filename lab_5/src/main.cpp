#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>
#include "../include/dynamic_array.hpp"

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
    // Создание экземпляра std::map с созданным аллокатором
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>, 10>> myMap;

    // Заполнение 10 элементами, где ключ — это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i < 10; ++i) {
        myMap[i] = factorial(i);
    }

    // Вывод на экран всех значений хранящихся в контейнере
    for (const auto& pair : myMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    // Создание экземпляра своего контейнера для хранения int с собственным аллокатором
    DynamicArray<int, 10> myArray;

    // Заполнение контейнера
    for (int i = 0; i < 10; ++i) {
        myArray.push_back(i);
    }

    // Печать его элементов
    for (const auto& value : myArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
