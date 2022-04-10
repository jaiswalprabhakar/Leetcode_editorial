#include <bits/stdc++.h>
using namespace std;
  
int twoSum2(vector<int> &nums, int target) {
    int n = nums.size(); 
    sort(nums.begin(), nums.end());
    int result = 0, l = 0, r = n - 1;
    while (l < r) {
        if (nums[l] + nums[r] <= target) {
            l++;
        } else {
            result += r - l;
            r--;
        }
    }

    return result;
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
    result = twoSum2(nums, target);
    cout<<result;
    return 0;
}