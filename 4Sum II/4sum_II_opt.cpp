#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int n = nums1.size(), count=0;
    unordered_map<int, int> mp;
    
    for(auto i:nums1){
        for(auto j:nums2){
            mp[i+j]++;
        }
    }
    
    for(auto i:nums3){
        for(auto j:nums4){
            if(mp.find(0-(i+j)) != mp.end())
                count += mp[0-(i+j)];
        }
    }
    return count;
}
int main(){
    int n,  result;
    cin>>n;
    vector<int> num1(n), num2(n), num3(n), num4(n);
    for(int i=0; i<n; i++){
        cin>>num1[i];
    }
    for(int i=0; i<n; i++){
        cin>>num2[i];
    }
    for(int i=0; i<n; i++){
        cin>>num3[i];
    }
    for(int i=0; i<n; i++){
        cin>>num4[i];
    }
    result = fourSumCount(num1, num2, num3, num4);
    cout<<result<<endl;
    return 0;
}