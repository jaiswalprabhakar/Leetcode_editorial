#include <bits/stdc++.h>
using namespace std;
  
int twoSum6(vector<int> &nums, int target) {
    if(nums.size() < 2) return 0;
    int l = 0, r = nums.size()-1;
    int count = 0;
    sort(nums.begin(), nums.end());
    while(l < r) {
        if(l > 0 && nums[l] == nums[l-1]) {
            l++;
            continue;
        }
        if(nums[l] + nums[r] == target) {
            count++;
            l++;
            r--;
        } else if (nums[l] + nums[r] < target) {
            l++;
        } else {
            r--;
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
    result = twoSum6(nums, target);
    cout<<result;
    return 0;
}