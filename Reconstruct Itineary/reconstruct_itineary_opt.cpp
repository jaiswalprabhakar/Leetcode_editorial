#include <bits/stdc++.h>
using namespace std;
map<string, multiset<string>> targets;
vector<string> route;
void visit(string airport) {
    while (targets[airport].size()) {
        string next = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        visit(next);
    }
    route.push_back(airport);
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto ticket : tickets)
        targets[ticket.first].insert(ticket.second);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
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
  