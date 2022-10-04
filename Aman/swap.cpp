#include <bits/stdc++.h>
using namespace std;

char smallest_alphabet(string a, int n)
{
    char min = 'z';
    for (int i=n-1; i>=0; i--)   
        if (a[i] < min)
            min = a[i];   
    return min;
}

int main(){
    string str;
    char temp;
    cin>>str;
    int n;
    cin>> n;
    int size = sizeof(str) / sizeof(str[0]);
    for(int i=0; i<n; i++){
        temp = smallest_alphabet(str, size);
    }
}