#include <bits/stdc++.h>
using namespace std;
  
vector<int> twoSum(vector<int>& nums, int target) {
    // Keys are the array values and values are the associated array indices
    unordered_map<int, int> hash; // Use as a hash table, instead of creating one
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
        if (hash.count(target - nums[i])) // If the partner of this value to reach the target sum has been saved already
        {
            result.push_back(hash[target - nums[i]]); // Get index of other value
            result.push_back(i);
            return result;
        }
        else // Pair has not yet been found, so save value to hash table
            hash[nums[i]] = i;
    return result;
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
    result = twoSum(nums, target);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}