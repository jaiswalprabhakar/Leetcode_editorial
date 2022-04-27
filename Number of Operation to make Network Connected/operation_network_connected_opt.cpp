#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
{
    visited[src] = true;
    for(int i : adj[src])
        if(!visited[i])
            dfs(adj, visited, i);
}
int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n - 1)
        return -1;
    vector<vector<int>> adj(n);
    for(auto v : connections)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    vector<bool> visited(n, false);
    int components = 0;
    for(int i=0; i<n; i++)
        if(!visited[i])
        {
            dfs(adj, visited, i);
            components++;
        }
    return components - 1;
}
int main()
{
    int n,m,temp;
    cin>>n>>m;
    vector<vector<int>> connection;
    for(int i=0; i<m; i++){
      vector<int> v1;
      for(int j=0; j<2; j++){
        cin>>temp;
        v1.push_back(temp);
      }
      connection.push_back(v1);
    }
	int result = makeConnected(n, connection);
    cout<<result;
	return 0;
}