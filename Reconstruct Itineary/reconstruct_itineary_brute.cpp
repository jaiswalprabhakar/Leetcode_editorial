#include <bits/stdc++.h>
using namespace std;

unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
vector<string> result;
void dfs(string vtex)
{
    auto & edges = graph[vtex];
    while (!edges.empty())
    {
        string to_vtex = edges.top();
        edges.pop();
        dfs(to_vtex);
    }
    result.push_back(vtex);
}
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto e : tickets)
        graph[e.first].push(e.second);
    dfs("JFK");
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    int n;
    cin>>n;
    string temp1, temp2;
    vector<pair<string,string>> ticket;
    for(int i=0; i<n; i++){
        cin>>temp1>>temp2;
        ticket.push_back(make_pair(temp1, temp2));
    }
	vector<string> result = findItinerary(ticket);
    for(int i=0; i< result.size(); i++){
        cout<<result[i]<<" ";
    }
	return 0;
}
  