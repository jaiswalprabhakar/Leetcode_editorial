#include <bits/stdc++.h>
using namespace std;
 
void creategraph(vector<vector<int>>Edges,unordered_map<int,list<int>>&l){
  for(int i=0;i<Edges.size();i++){
      int u=Edges[i][0],v=Edges[i][1];
      l[u].push_back(v);
      l[v].push_back(u);
  }
}
bool Hp(int i,vector<int>&path,vector<int>&visited,unordered_map<int,list<int>>&l){
    path.push_back(i);
    visited[i]=1;
    if(path.size()==l.size())
    return true;
    for(auto x:l[i]){
        if(!visited[x]){
            if(Hp(x,path,visited,l))
            return true;
        }
    }
    path.pop_back();
    visited[i]=0;
    return false;
}
bool check(int N,int M,vector<vector<int>> Edges){
    vector<int>path,visited(N+1,0);
    unordered_map<int,list<int>>l;
    creategraph(Edges,l);
    for(int i=1;i<=N;i++){
        if(Hp(i,path,visited,l))
        return true;
    }
    return false;
}
int main()
{
    int N,M,temp;
    cin>>N>>M;
    vector<vector<int>> edges;
    for(int i=0; i<M; i++){
      vector<int> v1;
      for(int j=0; j<2; j++){
        cin>>temp;
        v1.push_back(temp);
      }
      edges.push_back(v1);
    }
    cout<<(check(N,M,edges));
    return 0;
}