#include <bits/stdc++.h>
using namespace std;
  
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> v;
    int i=0,j=0;
    while(i<A.size() && j<B.size()){
        int l=max(A[i][0], B[j][0]);
        int u=min(A[i][1], B[j][1]);
        if(l<=u) 
            v.push_back({l,u});
        if(A[i][1] < B[j][1])   
            i++;
        else 
            j++;
    }
    return v;
}
int main() { 
    int m, n;
    cin>>n;
    vector<vector<int>> first;
    for(int i=0; i<n; i++){
        vector<int> temp(2);
        for(int j=0; j<2; j++){
            cin>>temp[j];
        }
        first.push_back(temp);
    }
    cin>>m;
    vector<vector<int>> second;
    for(int i=0; i<m; i++){
        vector<int> temp(2);
        for(int j=0; j<2; j++){
            cin>>temp[j];
        }
        second.push_back(temp);
    }
    vector<vector<int>> result;
    result = intervalIntersection(first, second);
    for(int i=0; i< result.size(); i++){
        for(int j=0; j<2; j++){
            cout<<result[i][j]<<" ";
        }
    }
    return 0; 
} 