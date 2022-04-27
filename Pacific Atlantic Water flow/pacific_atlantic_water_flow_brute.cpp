#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int> > ans;
vector<vector<bool> > atlantic, pacific;
queue<pair<int, int> > q;
void bfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
    q.push({i, j});
    while(!q.empty()){
        tie(i, j) = q.front(); q.pop();
        if(visited[i][j]) continue;
        visited[i][j] = true;
        if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
        if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) q.push({i + 1, j});
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) q.push({i - 1, j});
        if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) q.push({i, j + 1});
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) q.push({i, j - 1});
    }
}
vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
    if(!mat.size()) return ans;
    m = mat.size(), n = mat[0].size();
    atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++) bfs(mat, pacific, i, 0), bfs(mat, atlantic, i, n - 1);
    for(int i = 0; i < n; i++) bfs(mat, pacific, 0, i), bfs(mat, atlantic, m - 1, i);             
    return ans;
}

int main(){
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
  