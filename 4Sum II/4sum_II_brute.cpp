#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int count = 0;
    for(int i : nums1)
        for(int j : nums2)
            for(int k : nums3)
                for(int l : nums4)
                    if(i + j + k + l == 0) count++;
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