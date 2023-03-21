#include "./utils/tools.hh"

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

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, atoi(argv[1]));
    take_time(bubbleSort, myVector);
}