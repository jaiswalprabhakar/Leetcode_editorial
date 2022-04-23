#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> A) {
    int n = A.size();
    int left=0; int right=n-1;
    int res=0;
    int maxleft=0, maxright=0;
    while(left<=right){
        if(A[left]<=A[right]){
            if(A[left]>=maxleft) maxleft=A[left];
            else res+=maxleft-A[left];
            left++;
        }
        else{
            if(A[right]>=maxright) maxright= A[right];
            else res+=maxright-A[right];
            right--;
        }
    }
    return res;
}
int main(){
    int n, result;
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    result = trap(height);
    cout<<result;
    return 0;

}