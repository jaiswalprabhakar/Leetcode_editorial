#include <bits/stdc++.h>
using namespace std;
  
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<=n-1;i++){
        
        for(int j=i+1;j<=n-1;j++){
            
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                
            }
            
        }
    }
    
    return ans;
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