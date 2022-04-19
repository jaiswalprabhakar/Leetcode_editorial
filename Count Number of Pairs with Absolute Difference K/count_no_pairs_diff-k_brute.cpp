#include <bits/stdc++.h>
using namespace std;

int countKDifference(vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();
    // Pick all elements one by one
    for (int i = 0; i < nums.size() ; i++){
        for (int j = i + 1; j < n; j++)
            if (nums[i] - nums[j] == k ||nums[j] - nums[i] == k)
                count++;
    }
    return count;
}
int main() {
    int n, k, ans;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin>>k;
    ans = countKDifference(nums, k);
    cout << ans << "\n";
    return 0;
}  