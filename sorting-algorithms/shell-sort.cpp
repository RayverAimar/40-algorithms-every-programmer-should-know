#include "./utils/tools.hh"

template <typename T>
void shellSort(std::vector<T>& arr, bool reverse = false)
{
    bool (*comp) (T&, T&);
    if (reverse) comp = isSmaller;
    else comp = isGreater;

    for(int shift = arr.size() >> 2; shift > 0; shift >>= 2)
    {
        for(int i = shift; i < arr.size(); i++)
        {
            T temp = arr[i];
            int j;
            for(j = i; j >= shift && comp(arr[j - shift],temp); j-=shift)
            {
                arr[j] = arr[j - shift];
            }
            arr[j] = temp;
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, atoi(argv[1]));
    take_time(shellSort, myVector);
}