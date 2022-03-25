#include <bits/stdc++.h>
using namespace std;
  
bool isSumEqual(string a, string b, string c) {
    int f1=0,f2=0,f3=0;
    int a1=a.size(),b1=b.size(),c1=c.size();
    for(int i=0;i<a1;i++)
    {
        f1 *= 10;
        f1 += (a[i]-'a');
    }
    for(int i=0;i<b1;i++)
    {
        f2 *= 10;
        f2 += (b[i]-'a');
    }
    for(int i=0;i<c1;i++)
    {
        f3 *= 10;
        f3 += (c[i]-'a');
    }
    return (f1+f2==f3);
}
int main() { 
    string first, second, target;
    cin>>first>>second>>target;
    cout<<isSumEqual(first,second,target);
    return 0; 
} 