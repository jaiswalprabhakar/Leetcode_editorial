#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& image, int i, int j,int oldColor ,int newColor){

    if(i < 0 || i >= image.size() || 
        j < 0 || j >= image[0].size() || 
    image[i][j] != oldColor) return;
    
    image[i][j] = newColor;
    
    dfs(image, i-1, j, oldColor, newColor);
    dfs(image, i+1, j, oldColor, newColor);
    dfs(image, i, j-1, oldColor, newColor);
    dfs(image, i, j+1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    int oldColor = image[sr][sc];
    
    if(oldColor != newColor) 
        dfs(image, sr, sc, oldColor ,newColor);

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
  