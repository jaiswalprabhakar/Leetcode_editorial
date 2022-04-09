#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0, j=0, l, r;
        while(i<n){
            j=i+1;
            while(j<n){
                int sum=target-nums[i]-nums[j];
                l=j+1; r=n-1;
                while(l<r){
                    int x = nums[l]+nums[r];
                    int y = nums[l], z= nums[r] ;
                    if(x>sum)
                        r--;
                    else if(x<sum)
                        l++;
                    else{
                        ans.insert({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[r]==z)r--;
                        while(l<r && nums[l]==y)l++;
                    }
                }j++;
               
            }i++;
        }
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
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