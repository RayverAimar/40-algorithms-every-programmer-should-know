#include "./utils/tools.hh"

using namespace std;

template<typename T>
int linearSearch(std::vector<T>& arr, T element)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
    if(argc != 2) return -1;
    srand(time(NULL));
    std::vector<int> myVector;
    poblate_vector(myVector, atoi(argv[1]));
    int random_position = rand() % atoi(argv[1]);
    myVector[random_position] = 1235;
    take_time(linearSearch, myVector, 1235);
}