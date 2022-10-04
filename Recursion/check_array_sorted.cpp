#include <iostream>
using namespace std;

bool sorted_or_not(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    return sorted_or_not(arr + 1, size - 1);
}
int main()
{
    int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    bool output = sorted_or_not(arr, size);
    cout << output << endl;
    return 0;
}