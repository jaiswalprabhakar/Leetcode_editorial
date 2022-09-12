#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int val, int start, int end){
    while(start<end){
        if(arr[(start + end)/2]== val){
            return (start + end)/2 +1;
        }
        else if(arr[(start + end)/2] > val){
            end = (start + end)/2  -1;
        }
        else{
            start = (start + end)/2 +1;
        }
    }
    return -1;
}
int main(){
    int n, val;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter value to search";
    cin>>val;
    cout<<binarySearch(arr, val, 0, n-1);
}