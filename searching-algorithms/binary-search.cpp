#include <algorithm>

#include "./utils/tools.hh"

using namespace std;

template<typename T>
int binarySearch(std::vector<T>& arr, int l, int r, T element)
{
    if(r < l) return -1;
    int m = l + (r - l) / 2;
    if(arr[m] == element) return m;
    if(arr[m] > element) return binarySearch(arr, l, m - 1, element);
    return binarySearch(arr, m + 1, r, element);
}

template<typename T>
int binarySearchRecursiveManager(std::vector<T>& arr, T element)
{
    return binarySearch(arr, 0, arr.size() - 1, element);
}

template<typename T>
int binarySearchIterativeManager(std::vector<T>& arr, T element)
{
    int l = 0, r = arr.size() - 1, m;
    while(l < r)
    {
        m = (l + r) / 2;
        if(arr[m] > element)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    if(arr[l] == element) return l;
    else if(arr[r] == element) return r;
    else if(arr[m] == element) return m;
    else return - 1;
}

int main(int argc, char* argv[])
{
    if(argc != 2) return -1;
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, atoi(argv[1]));
    int random_position = rand() % atoi(argv[1]);
    myVector[random_position] = 1235;
    std::sort(myVector.begin(), myVector.end());
    take_time(binarySearchIterativeManager, myVector, 1235);
}