#include <bits/stdc++.h>
using namespace std;
  
int tupleSameProduct(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> umap;
    int res = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < i ; ++j){
            int prod = nums[i] * nums[j];
            /*Every tuple has 8 permutations*/
            res += 8 * umap[prod];
            ++umap[prod];
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
    result = tupleSameProduct(nums);
    cout<<result<<" ";
    return 0;
}