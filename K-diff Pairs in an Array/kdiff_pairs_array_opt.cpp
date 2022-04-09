#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int best = numeric_limits<int>::max();
    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int gap = nums[i] + nums[l] + nums[r] - target;
            if (abs(gap) < abs(best)) best = gap;
            else if (gap < 0)
                ++l;
            else
                --r;
        }
    }
    return target + best;
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
    result = threeSumClosest(nums, target);
    cout<<result<<" ";
    return 0;
}