#include <bits/stdc++.h>
using namespace std;

const int maxn=40009;
vector<int>adj[maxn];
pair<int,int> bfs(int s,int n){
    int dist[n];
    for(int i=0;i<n;i++)
        dist[i]=-1;
    dist[s]=0;
    int maxDist=0;
    int maxDistNode=s;
    queue<int>q;
    q.push(s);
    while(q.empty()==false){
        int temp=q.front();
        q.pop();
        for(int v:adj[temp]){
            if(dist[v]==-1){
                dist[v]=dist[temp]+1;
                q.push(v);
                if(dist[v]>maxDist){
                    maxDist=dist[v];
                    maxDistNode=v;
                }
            }
        }
    }
    return {maxDistNode,maxDist};
}
int solve(vector<int> &A) {
    int root;
    int n=A.size();
    assert(n>=1 && n<=40000);
    int flag=0;
    for(int a:A){
        if(a==-1)flag++;
        else assert(a>=0 && a<n);
    }
    assert(flag==1);
    for(int i=0;i<n;i++)
        adj[i].clear();
    for(int i=0;i<A.size();i++){
        if(A[i]==-1){
            root=i;
            continue;
        }
        else{
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }
    pair<int,int> a = bfs(root,n);
    pair<int,int> b = bfs(a.first,n);
    return b.second;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int result = solve(v);
    cout<<result<<"\n";
    return 0;
}