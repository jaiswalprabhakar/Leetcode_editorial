#include <bits/stdc++.h>
using namespace std;
  
int twoSumLessThanK(vector<int>& A, int K, int S = -1) {
    int nums[1001] = {};
    for (auto i : A) 
        ++nums[i];
    for (int i = 1, j = 1000; i <= j;) {
        if (!nums[j] || i + j >= K)
            --j;
    else{
        if (nums[i] > 0 + (i == j))
            S = max(S, i + j);
        ++i;
    } 
}
    return S;
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
    result = twoSumLessThanK(nums, target);
    cout<<result;
    return 0;
}