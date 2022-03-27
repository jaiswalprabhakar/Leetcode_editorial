#include <bits/stdc++.h>
using namespace std;
  
vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
	vector<int> ans(queries.size());
	for(int i = 0; i < queries.size(); i++){
		int x = queries[i][0], y = queries[i][1], r = queries[i][2];
		for(int j = 0; j < points.size(); j++){
			if((x - points[j][0]) * (x - points[j][0]) + (y - points[j][1]) * (y - points[j][1]) <= r * r)    
				ans[i]++;
		}            
	}
	return ans;
}
int main() { 
    int m, n;
    cin>>n;
    vector<vector<int>> points;
    for(int i=0; i<n; i++){
        vector<int> temp(2);
        for(int j=0; j<2; j++){
            cin>>temp[j];
        }
        points.push_back(temp);
    }
    cin>>m;
    vector<vector<int>> queries;
    for(int i=0; i<m; i++){
        vector<int> temp(3);
        for(int j=0; j<3; j++){
            cin>>temp[j];
        }
        queries.push_back(temp);
    }
    vector<int> result;
    result = countPoints(points, queries);
    for(int i=0; i< m; i++){
        cout<<result[i]<<" ";
    }
    return 0; 
} 