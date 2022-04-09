#include <bits/stdc++.h>
using namespace std;
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int ans=0;
    for(int i=nums.size()-1; i>=2; i--)  {
        for(int j=i-1; j>=1; j--) {
            auto itr=upper_bound(nums.begin(), nums.end(), nums[i]-nums[j]);  
            int ind=itr-nums.begin(); 
            if(ind<=j){    //To make sure  the side a we get is before the side b in the sorted array 
                ans+=(j-ind); 
            }
        }   
    }   
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int result;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    result = triangleNumber(nums);
    cout<<result<<" ";
    return 0;
}