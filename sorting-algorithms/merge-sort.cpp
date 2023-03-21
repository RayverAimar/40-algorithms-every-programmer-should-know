#include "./utils/tools.hh"

template <typename T>
void merge(std::vector<T>& arr, const int l, const int m, const int r, bool reverse)
{
    bool (*comp) (T&, T&);
    if (reverse) comp = isSmaller;
    else comp = isGreater;

    const int lhs = m - l + 1;
    const int rhs = r - m;

    T *l_arr = new T[lhs], *r_arr = new T[rhs];
    
    for(int i = 0; i < lhs; i++)
    {
        l_arr[i] = arr[l + i];
    }
    for(int i = 0; i < rhs; i++)
    {
        r_arr[i] = arr[m + i + 1];
    }

    int idx_l_arr = 0, idx_r_arr = 0, idx_partition = l;

    while(idx_l_arr < lhs && idx_r_arr < rhs)
    {
        if(comp(l_arr[idx_l_arr], r_arr[idx_r_arr]))
        {
            arr[idx_partition] = l_arr[idx_l_arr];
            idx_l_arr++;
        }
        else
        {
            arr[idx_partition] = r_arr[idx_r_arr];
            idx_r_arr++;
        }
        idx_partition++;
    }

    while (idx_l_arr < lhs)
    {
        arr[idx_partition++] = l_arr[idx_l_arr++];
    }
    while(idx_r_arr < rhs)
    {
        arr[idx_partition++] = r_arr[idx_r_arr++];
    }
    
    delete[] l_arr;
    delete[] r_arr;
}

template <typename T>
void mergeSort(std::vector<T>& arr, const int low, const int high, bool reverse)
{
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid, reverse);
    mergeSort(arr, mid + 1, high, reverse);
    merge(arr, low, mid, high, reverse);
}

template<typename T>
void mergeSortManager(std::vector<T>& arr, bool reverse = false)
{
    mergeSort(arr, 0, arr.size() - 1, reverse);
}

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, atoi(argv[1]));
    take_time(mergeSortManager, myVector);
}