#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int rows=image.size(), cols=image[0].size(), oldColor=image[sr][sc];
    if(newColor==oldColor) return image;
    list<vector<int>> togo; togo.push_back({sr,sc});
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while(togo.size()) {
        int r=togo.front()[0], c=togo.front()[1]; togo.pop_front();
        image[r][c]=newColor;
        for(auto& d:dirs) {
            int rr=r+d[0], cc=c+d[1];
            if(rr<0 || rr>=rows ||cc<0 ||cc>=cols) continue; // keep togo safe
            if(image[rr][cc]!=oldColor) continue;            // keep togo clean
            togo.push_back({rr,cc});
        }
    }
    return image;
}
int main()
{
    int n,m,start, end, color, temp;
    cin>>n;
    cin>>m;
    vector<vector<int>> image;
    for(int i=0; i<n; i++){
      vector<int> v1;
      for(int j=0; j<m; j++){
        cin>>temp;
        v1.push_back(temp);
      }
      image.push_back(v1);
    }
    cin>>start>>end>>color;
	vector<vector<int>> result = floodFill(image, start, end, color);
    for(int i=0; i< result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
  