#include "./utils/tools.hh"

template <typename T>
void insertionSort(std::vector<T>& arr, bool reverse = false)
{
    bool (*comp) (T&, T&);
    if (reverse) comp = isSmaller;
    else comp = isGreater;

    for(size_t i = 1; i < arr.size(); i++)
    {
        T next_element = arr[i];
        int j = i - 1;
        while(j >= 0 && comp(arr[j], next_element))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = next_element;
    }
    
}

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, atoi(argv[1]));
    take_time(insertionSort, myVector);
}