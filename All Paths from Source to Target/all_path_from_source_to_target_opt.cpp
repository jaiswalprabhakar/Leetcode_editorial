#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& G) {
    vector<int> path;
    dfs(G, 0, path);
    return ans;
}
void dfs(vector<vector<int>>& G, int i, vector<int>& path) {
    path.push_back(i);                            // add current node to path
    if(i == size(G)-1) ans.push_back(path);       // valid path found
    else 
        for(auto child : G[i])  
            dfs(G, child, path);                  // recurse for every possible next node in path
    path.pop_back();                              // backtrack
}

int main()
{
    int n,target, K;
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    cin>>target;
    cin>>K;
	vector<vector<int>> result =  kSum(A, target, K);
    for(int i=0; i< result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
  