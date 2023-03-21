#include "./utils/tools.hh"

template <typename T>
int partition(std::vector<T>& arr, int l, int r, bool reverse)
{
    bool (*comp) (T&, T&);
    if (reverse) comp = isSmaller;
    else comp = isGreater;

    int pivot = arr[l];
    int i = l, j = r;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if(i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;

}

template<typename T>
void quickSort(std::vector<T>& arr, int l, int r, bool reverse)
{
    if(l >= r) return;
    int partition_idx = partition(arr, l, r, reverse);
    quickSort(arr, l, partition_idx - 1, reverse);
    quickSort(arr, partition_idx + 1, r, reverse);
}

template<typename T>
void quickSortManager(std::vector<T>& arr, bool reverse = false)
{
    quickSort(arr, 0, arr.size() - 1, reverse);
}

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, atoi(argv[1]));
    take_time(quickSortManager, myVector);
}