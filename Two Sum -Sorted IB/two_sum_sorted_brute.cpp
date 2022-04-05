#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int N = nums.size();
    for(int i=0;i<N-1;i++){
        int lo = i+1;
        int hi = N;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target-nums[i]) return {i+1,mid+1};
            else if(nums[mid]>=target-nums[i]) hi=mid;
            else lo = mid+1;
        }
        if(lo!=nums.size() && nums[lo]==target-nums[i]) return {i+1,lo+1};
    }
    return {}; // not found
}
int main(){
    int n, target;
    cin>>n;
    vector<int> nums(n);
    vector<int> result;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cin>>target;
    result = twoSum(nums, target);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}