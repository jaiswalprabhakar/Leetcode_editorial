#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(vector<int> arr, int si, int ei, int target) {
    vector<vector<int>> res;
    int left = si;
    int right = ei;

    while (left < right) {
      if (left != si && arr[left] == arr[left - 1]) {
        left++;
        continue;
    }

    int sum = arr[left] + arr[right];
    if (sum == target) {
        vector<int> list;
        list.push_back(arr[left]);
        list.push_back(arr[right]);
        res.push_back(list);

        left++;
        right--;
      } else if (sum > target) {
        right--;
      } else {
        left++;
      }
    }
    return res;
}

vector<vector<int>> kSumHelper(vector<int> nums, int target, int k, int si) {
    if (k == 2) {
      return twoSum(nums, si, nums.size() - 1, target);
    }
    vector<vector<int>> res;
    int n = nums.size();
    if (n < k) return res;
    for (int i = si; i <= n - k; i++) {
      if (i != si && nums[i] == nums[i - 1]) continue;

      int val = nums[i];
      int targ = target - val;
      vector<vector<int>> ans = kSumHelper(nums, targ, k - 1, i + 1);
      for (vector<int> list : ans) {
        list.push_back(val);
        res.push_back(list);
      }
    }
    return res;
}

vector<vector<int>> kSum(vector<int> arr, int target, int k) {
    sort(arr.begin(), arr.end());
    return kSumHelper(arr, target, k, 0);
}
int main()
{
    int n,target, K;
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    cin>>target;
    cin>>K;
	vector<vector<int>> result =  kSum(A, target, K);
    for(int i=0; i< result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
  