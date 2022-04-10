#include <bits/stdc++.h>
using namespace std;
  
int tupleSameProduct(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int ans = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int count = 0;
            int prod = nums[i] * nums[j];
            int k=0,l=n-1;
            while(k < l){
                if(k == i or k == j) { k++; continue; }
                if(l == i or l == j) { l--; continue; }
                int ele1 = nums[k], ele2 = nums[l];
                int curr_prod = ele1 * ele2;
                if(curr_prod > prod) l--;
                else if(curr_prod < prod) k++;
                else count++, k++,l--;
            }
            ans += (count * 4);
        }
    }
    return ans;
}
int main(){
    int n, target;
    cin>>n;
    vector<int> nums(n);
    int result;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    result = tupleSameProduct(nums);
    cout<<result<<" ";
    return 0;
}