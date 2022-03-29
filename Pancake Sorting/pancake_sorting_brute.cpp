#include <bits/stdc++.h>
using namespace std;

void flip(vector<int>& A, int ind) {
    int s = 0, e = ind;
    while(s<e) {
        swap(A[s++], A[e--]);
    }
}

int find(int tar, vector<int> A) {
    for(int i=0;i<A.size();i++)
        if(tar == A[i])
            return i;
    return -1;
}  
vector<int> pancakeSort(vector<int>& A) {
    int n = A.size();
    vector<int> ans;
    for(int i=n;i>0;i--)  {
        int ind = find(i, A);
        if(ind != (i - 1)) {
            if (ind != 0) {
                flip(A, ind);
                ans.push_back(ind + 1);
            }
            flip(A, i - 1);
            ans.push_back(i);
        }
    }
    return ans;
}
int main() { 
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> result;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    result = pancakeSort(arr);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0; 
} 