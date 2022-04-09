#include <bits/stdc++.h>
using namespace std;
int triangleNumber(vector<int>& nums) {
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(nums[i]+nums[j]>nums[k])
                    count++;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int result;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    result = triangleNumber(nums);
    cout<<result<<" ";
    return 0;
}