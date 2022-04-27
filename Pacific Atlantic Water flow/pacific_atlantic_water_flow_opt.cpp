#include <bits/stdc++.h>
using namespace std;
int m, n;
// denotes cells reachable starting from atlantic and pacific edged cells respectively
vector<vector<bool> > atlantic, pacific;
vector<vector<int> > ans;    
void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
    if(visited[i][j]) return;
    visited[i][j] = true;
    // if cell reachable from both the oceans, insert into final answer vector
    if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});    
    // dfs from current cell only if height of next cell is greater
/*⬇️*/  if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
/*⬆️*/  if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
/*➡️*/  if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
/*⬅️*/  if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
}


vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
    if(!mat.size()) return ans;
    m = mat.size(), n = mat[0].size();
    atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
    // perform dfs from all edge cells (ocean-connected cells)
    for(int i = 0; i < m; i++) dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, n - 1);
    for(int i = 0; i < n; i++) dfs(mat, pacific, 0, i), dfs(mat, atlantic, m - 1, i);             
    return ans;
}

int main()
{
    int n,m,temp;
    cin>>n>>m;
    vector<vector<int>> mat;
    for(int i=0; i<n; i++){
      vector<int> v1;
      for(int j=0; j<m; j++){
        cin>>temp;
        v1.push_back(temp);
      }
      mat.push_back(v1);
    }
	vector<vector<int>> result = pacificAtlantic(mat);
    for(int i=0; i< result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
  