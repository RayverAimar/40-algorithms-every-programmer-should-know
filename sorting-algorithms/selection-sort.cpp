#include "./utils/tools.hh"

template <typename T>
void selectionSort(std::vector<T>& arr, bool reverse = false)
{
    bool (*comp) (T&, T&);
    if (reverse) comp = isSmaller;
    else comp = isGreater;

    for(size_t i = 0; i < arr.size() - 1; i++)
    {
        int idx_min = i;
        for(size_t j = i + 1; j < arr.size(); j++)
        {
            if(comp(arr[i], arr[j]))
            {
                idx_min = j;
            }
        }
        swap(arr[i], arr[idx_min]);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, atoi(argv[1]));
    take_time(selectionSort, myVector);
}