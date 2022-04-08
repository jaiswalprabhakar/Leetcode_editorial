#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target){
    int n = nums.size();
    int ans = INT_MAX;
    for (int i = 0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans)){
                    ans = sum - target;
                }
            }
        }
    }
    return ans + target;
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