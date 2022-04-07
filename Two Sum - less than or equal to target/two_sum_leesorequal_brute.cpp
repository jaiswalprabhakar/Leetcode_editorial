#include <bits/stdc++.h>
using namespace std;
  
int twoSumLessThanK(vector<int>& A, int K, int S = -1) {
    sort(begin(A), end(A));
    for (int i = 0, j = A.size() - 1; i < j; ) {
        if (A[i] + A[j] < K) 
            S = max(S, A[i++] + A[j]);
        else 
            --j;
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