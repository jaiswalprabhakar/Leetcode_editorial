#include <iostream>
using namespace std;

int fibunacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibunacci(n - 1) + fibunacci(n - 2);
}
int main()
{
    int n;
    cin >> n;
    int output = fibunacci(n);
    cout << output << endl;
    return 0;
}