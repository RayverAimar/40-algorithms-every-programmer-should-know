#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>

#define N 10000
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

template <typename T>
void bubbleSort(std::vector<T>& arr, bool reverse = false)
{
    bool (*comp) (T&, T&);
    if (reverse) comp = isSmaller;
    else comp = isGreater;

    for(size_t i = 0; i < arr.size() - 1; i++)
    {
        for(size_t j = 0; j < arr.size() - 1; j++)
        {
            if(comp(arr[j], arr[j+1]))
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
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
void take_time(void (*func) (std::vector<T>&, bool), std::vector<T>& arr, bool reverse = false)
{
    auto start = Time::now();
    func(arr, reverse);
    auto end = Time::now();
    fsec fs = end - start;
    std::cout << fs.count() << "s" << std::endl;
}

int main()
{
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, N);
    take_time(bubbleSort, myVector);
}