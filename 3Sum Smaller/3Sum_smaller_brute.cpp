#include <bits/stdc++.h>
using namespace std;

int threeSumSmaller(vector<int>& nums, int target) {
    int res = 0, size = nums.size();
    sort(nums.begin(), nums.end()); // sort the array first
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1, k = size - 1; j < k; --k) // 2 pointers
        {
            while (j < k && nums[i] + nums[j] + nums[k] < target) // (i, j, k) < target
            {
                res += k - j; // add k - j # of pairs as described above
                ++j;
            }
        }
    }
    
    return res;
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