#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>

#define N 10000
#define LEAST_TO_PRINT 20
#define print_vector(v) for(int i = 0; i < v.size(); i++) std::cout << v[i] << " "; std::cout << std::endl;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::duration<float> fsec;

template <typename T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
bool isGreater(T& a, T& b)
{
    return a > b;
}

template <typename T>
bool isSmaller(T& a, T& b)
{
    return a < b;
}

template<typename T>
void poblate_vector(std::vector<T>& arr, size_t size)
{
    arr.clear();
    for(size_t i = 0; i < size; i++)
    {
        arr.push_back(T(std::rand()));
    }
}

template<typename T>
void take_time(int (*func) (std::vector<T>&, T), std::vector<T>& arr, T element)
{
    auto start = Time::now();
    int idx = func(arr, element);
    auto end = Time::now();
    fsec fs = end - start;
    std::cout << "Elapsed time: " << fs.count() << "s" << std::endl;
    std::cout << "The element is in the index " << idx << std::endl;
    if (arr.size() <= LEAST_TO_PRINT)
    {
        print_vector(arr);
    }
}