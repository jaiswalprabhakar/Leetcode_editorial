#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int l=0,r=height.size()-1;
    int max_area=0;
    
    while(l<r){
        int lh=height[l];
        int rh=height[r];
        
        max_area=max(max_area,(r-l)*min(lh,rh));
        
        if(lh<rh) ++l;
        else --r;
    }
    
    return max_area;
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