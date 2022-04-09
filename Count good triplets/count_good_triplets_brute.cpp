#include <bits/stdc++.h>
using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int lks=0;
    for(int i=0;i<arr.size()-2;i++)
        for(int j=i+1;j<arr.size()-1;j++)
            for(int k=j+1;k<arr.size();k++){
                int x=arr[i],y=arr[j],z=arr[k];
                if(abs(x-y)<=a && abs(y-z)<=b && abs(x-z)<=c) lks+=1;
            }
    return lks;
}
int main(){
    int n,a,b,c, result;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cin>>a>>b>>c;
    result = countGoodTriplets(nums, a,b,c);
    cout<<result<<" ";
    return 0;
}