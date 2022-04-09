#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        nums1 = nums;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                twoSums[nums[i] + nums[j]].push_back({i, j});
            }
        }
        
        for (auto [key, value] : twoSums) {
            int tmp = target - key;
            if (twoSums.find(tmp) != twoSums.end()) makePairs(twoSums[key], twoSums[tmp]);
        }
        
        vector<vector<int>> res(fourSums.begin(), fourSums.end()); 
        return res;
    }
    
    void makePairs(vector<pair<int, int>> arr1, vector<pair<int, int>> arr2) {
        for (auto [a, b] : arr1) {
            for (auto [c, d] : arr2) {
                if (a != c && b != c && a != d && b != d) {
                    vector<int> tmp = {nums1[a], nums1[b], nums1[c], nums1[d]};
                    sort(tmp.begin(), tmp.end());
                    fourSums.insert(tmp);
                } 
            }
        }
    }

private:
    set<vector<int>> fourSums;
    unordered_map<int, vector<pair<int, int>>> twoSums;
    vector<int> nums1;
};
int main(){
    int n, target;
    cin>>n;
    vector<int> nums(n);
    vector<vector<int>> result;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cin>>target;
    Solution *obj = new Solution();
    result = obj ->fourSum(nums, target);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}