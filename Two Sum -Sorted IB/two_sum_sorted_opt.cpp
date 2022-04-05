#include <bits/stdc++.h>
using namespace std;
  
vector<int> twoSum(vector<int>& nums, int target) {
    int i=0,j=nums.size()-1;
    while(i<j){
        int sum = nums[i] + nums[j];
        if(sum==target) return {i+1,j+1};
        else if(sum>target) j--;
        else i++;
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