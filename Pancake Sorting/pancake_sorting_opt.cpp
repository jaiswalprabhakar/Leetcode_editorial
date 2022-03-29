#include <bits/stdc++.h>
using namespace std;

int getPos(vector<int>& arr, int k)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==k)
            return i;
    }
    return -1;
}

void reverseArr(vector<int>& arr, int k)
{
    int i=0,j=k;
    while(i<j)
    {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
vector<int> pancakeSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> res;
    for(int i=n;i>0;i--){
        int pos = getPos(arr,i);
        if(pos==i-1)
            continue;
        else if(pos!=0)
        {
            res.push_back(pos+1);
            reverseArr(arr,pos);
        }
        res.push_back(i);
        revers
    return res;
}
int main() { 
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> result;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    result = pancakeSort(arr);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0; 
} 