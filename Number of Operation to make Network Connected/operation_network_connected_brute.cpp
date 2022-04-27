#include <bits/stdc++.h>
using namespace std;

int findParent(int pc, unordered_map<int, int>& pcParent){
    if (pc == pcParent[pc]){
        return pc;
    }
    return findParent(pcParent[pc], pcParent);
}
int makeConnected(int n, vector<vector<int>>& connections) {
    int red = 0;
    unordered_set<int> parents;
    unordered_map<int, int> pcParent;
    for (int i = 0; i < n; ++i){
        pcParent[i] = i;
    }
    for (const auto& c : connections){
        int p1 = findParent(c[0], pcParent), p2 = findParent(c[1], pcParent);
        pcParent[p1] = p2; // union
        red += p1 == p2 ? 1 : 0; // redundant edge
    }
    for (int i = 0; i < n; ++i){
        parents.insert(findParent(i, pcParent));
    }
    return red >=  parents.size() - 1 ? parents.size() - 1 : -1;
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