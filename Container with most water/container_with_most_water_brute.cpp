#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n= height.size();
    int ans= INT_MIN;
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int a= min(height[i], height[j])*(j-i);
            ans = max(ans,a);
        }
    }
    return ans;
}
int main(){
    int n, result;
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    result = maxArea(height);
    cout<<result;
    return 0;
}