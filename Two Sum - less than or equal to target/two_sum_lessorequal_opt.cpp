#include <bits/stdc++.h>
using namespace std;
  
int twoSum5(vector<int> &nums, int target) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum <= target) {
            ans += (r - l);
            l++;
        } else {
            r--;
        }
    }
    return ans;
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
    result = twoSum5(nums, target);
    cout<<result;
    return 0;
}