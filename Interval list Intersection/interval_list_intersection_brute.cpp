#include <bits/stdc++.h>
using namespace std;
  
vector<vector<int>> intervalIntersection(vector<vector<int>>&l1, vector<vector<int>>&l2) {
    vector<vector<int>>v;
    for(int i=0;i<l1.size();i++){
        for(int j=0;j<l2.size();j++){
            if(l1[i][1]<l2[j][0]) 
                break;
            int x=max(l1[i][0],l2[j][0]);
            int y=min(l1[i][1],l2[j][1]);
            if(x<=y) 
                v.push_back({x,y});
        }
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