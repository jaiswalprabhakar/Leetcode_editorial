#include <bits/stdc++.h>
using namespace std;

int threeSumSmaller(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int count=0;
    for(int i=0; i<n; i++){
        int lo = i+1;
        int hi = n-1;
        while(lo<hi){
            int sum = nums[i]+nums[lo]+nums[hi];
            if(sum<target){
                count+=(hi-lo);
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    return count;
}

int main(){
    int n, target;
    cin>>n;
    vector<int> nums(n);
    int result;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cin>>target;
    result = threeSumSmaller(nums, target);
    cout<<result<<" ";
    return 0;
}