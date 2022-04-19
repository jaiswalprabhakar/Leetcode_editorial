#include <bits/stdc++.h>
using namespace std;

int countKDifference(vector<int>& nums, int k) {
    int cnt[101] = {}, res = 0;
    for (auto n : nums)
        ++cnt[n];
    for (int i = k + 1; i < 101; ++i)
        res += cnt[i] * cnt[i - k];
    return res;
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