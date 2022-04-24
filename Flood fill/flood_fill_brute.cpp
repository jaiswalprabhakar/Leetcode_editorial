#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
  vector<vector<int>> graph(n);
  // Build the graph
  for(int i=0; i<edges.size(); i++) {
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
  }
  
  // BFS
  queue<int> q;
  vector<int> visited(n, 0);
  q.push(start);
  visited[start] = 1;
  while(!q.empty()){
      int top = q.front();
      q.pop();
      if(top == end)
          return true;

      for(int i=0; i<graph[top].size(); i++){
          if(visited[graph[top][i]] == 0){
              q.push(graph[top][i]);
              visited[graph[top][i]] = 1;
          }
      }
  }
  return false;
}

int main()
{
    int n,m,start, end, temp;
    cin>>n;
    cin>>m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
      vector<int> v1;
      for(int j=0; j<2; j++){
        cin>>temp;
        v1.push_back(temp);
      }
      edges.push_back(v1);
    }
    cin>>start>>end;
	bool result =  validPath(n,edges, start, end);
    cout<<result;
	return 0;
}
  