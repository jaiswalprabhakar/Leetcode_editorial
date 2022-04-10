#include <bits/stdc++.h>
using namespace std;
  
vector<int> twoSum7(vector<int> &nums, int target) {
    target = abs(target);
    for (int i = 0,j = 0; i < nums.size(); i++) {
        j = max(j ,i + 1);
        while (j < nums.size() && nums[j] - nums[i] < target) {
            j++;
        }
        if (j > nums.size()) {
            break;
        }
        if (nums[j] - nums[i] == target) {
            return vector<int> {nums[i],nums[j]};
        }
    }
    return vector<int> {-1,-1};
}

int main(){
    int n, target;
    cin>>n;
    vector<int> nums(n);
    vector<int> result;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cin>>target;
    result = twoSum7(nums, target);
    for(int i=0; i<result.size(); i++){
        cout<<result[i];
    }
    return 0;
}