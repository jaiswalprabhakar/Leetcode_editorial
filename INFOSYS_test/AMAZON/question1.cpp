#include <bits/stdc++.h>
using namespace std;

int getMaxtemperature(vector<int> arr){
    int n = arr.size(), sumLeft = 0, sumRight =0;
    int result = INT_MIN;
    for(int i= 0; i<n; i++){
        for(int j = 0; j <= i; j++){
            sumLeft += arr[j];
        }
        for(int k= i; k< n; k++){
            sumRight += arr[k];
        }
        if(result < max(sumLeft, sumRight)){
            result = max(sumLeft, sumRight);
        }
        sumLeft=0;
        sumRight=0;
    }
    return result;
}

int main(){
    int n, result;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    result = getMaxtemperature(arr);
    cout<<result;
}