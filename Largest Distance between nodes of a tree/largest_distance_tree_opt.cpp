#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    vector<int> hgt(A.size(),0);
    int ans=0,maxx=0;
    for(int i=A.size()-1;i>0;i--){
        ans=max(ans,hgt[A[i]]+hgt[i]+1);
        hgt[A[i]]=max(hgt[i]+1,hgt[A[i]]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int result = solve(v);
    cout<<result<<"\n";
    return 0;
}