#include<bits/stdc++.h>
using namespace std;
int main(){
    int N = 255, count=0;
    while (N > 0) {
        if (N & 1) {
            count++;
        }
        N = N >> 1;
    }
    cout<<count;
}