#include <bits/stdc++.h>
using namespace std;
  
int sqr(int a) {
    return a * a;
}
int find_left_boundry_index(vector<vector<int> > & points , int x_center , int y_center , int r) {
    int lo = 0, hi = points.size();
    while (lo < hi) {
        int mi = lo + (hi - lo ) / 2;
        if (x_center - r <= points[mi][0])
            hi = mi;
        else
            lo = mi + 1;
    }
    return hi == points.size() or (points[hi][0] > x_center + r or points[hi][0] < x_center - r) ? points.size() : hi;
}
vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    sort(points.begin(), points.end());
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++) {
        int x_center = queries[i][0], y_center = queries[i][1], r = queries[i][2];
        int index = find_left_boundry_index(points, x_center , y_center, r); 
        int count = 0;
        for (int j = index; j < points.size() and points[j][0] <= x_center + r; j++) {
            int x = points[j][0];
            int y = points[j][1];
            count += sqr(x_center - x) + sqr(y_center - y) <= r * r;
        }
        ans.push_back(count);
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