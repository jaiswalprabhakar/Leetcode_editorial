#include <bits/stdc++.h>
using namespace std;
  
int findTargetSumWays(vector<int>& nums, int S) {
	int sum = 0;
	for (auto n : nums) sum += n;
	if ((sum + S) % 2 == 1 || S > sum || S < -sum) return 0;
	int newS = (sum + S) / 2;
	vector<int> dp(newS + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = newS; j >= nums[i]; --j) {
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp[newS];
}
int main(){
    int n, target, result;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cin>>target;
    result = findTargetSumWays(nums, target);
    cout<<result;
    return 0;
}