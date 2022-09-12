#include <iostream>
using namespace std;

int getSum(int n)
{
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int main()
{
    int A,B, count=0;
    cin>>A>>B;
    while(getSum(A) > B){
        A++;
        count++;
    }
    cout<<count;
    return 0;
}