#include <bits/stdc++.h>
using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int len=arr.size();
    int ans=0;
    if(len<3) return ans;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(abs(arr[i]-arr[j])<=a)
                for(int k=j+1;k<len;k++){
                    if(abs(arr[j]-arr[k])<=b&&abs(arr[i]-arr[k])<=c)
                        ans++;
                }
        }
    }
    return ans;
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