#include <bits/stdc++.h>
using namespace std;
  
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<bool>> board(8, vector<bool>(8));
    for(vector<int> v : queens) board[v[0]][v[1]] = true;
        
    vector<vector<int>> ans;
    int ki = king[0], kj = king[1];
    
    //right
    for(int j=kj+1; j<8; j++){
        if(board[ki][j] == true){
            ans.push_back({ki, j});
            break;
        }
    }
    //left
    for(int j=kj-1; j>=0; j--){
        if(board[ki][j] == true){
            ans.push_back({ki, j});
            break;
        }
    }
    //top
    for(int i=ki-1; i>=0; i--){
        if(board[i][kj] == true){
            ans.push_back({i, kj});
            break;
        }
    }
    //bottom
    for(int i=ki+1; i<8; i++){
        if(board[i][kj] == true){
            ans.push_back({i, kj});
            break;
        }
    }
    //top right
    for(int i=ki-1, j=kj+1; i>=0 && j<8; i--, j++){
        if(board[i][j] == true){
            ans.push_back({i, j});
            break;
        }
    }
    //top left
    for(int i=ki-1, j=kj-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == true){
            ans.push_back({i, j});
            break;
        }
    }
    //bottom right
    for(int i=ki+1, j=kj+1; i<8 && j<8; i++, j++){
        if(board[i][j] == true){
            ans.push_back({i ,j});
            break;
        }
    }
    //bottom left
    for(int i=ki+1, j=kj-1; i<8 && j>=0; i++, j--){
        if(board[i][j] == true){
            ans.push_back({i, j});
            break;
        }
    } 
    return ans;
}
int main() { 
    int n;
    cin>>n;
    vector<vector<int>> queen;
    for(int i=0; i<n; i++){
        vector<int> temp(2);
        for(int j=0; j<2; j++){
            cin>>temp[j];
        }
        queen.push_back(temp);
    }
    vector<int> king(2);
    cin>>king[0]>>king[1];
    vector<vector<int>> result;
    result =  queensAttacktheKing(queen, king);
    for(int i=0; i< result.size(); i++){
        for(int j=0; j<2; j++){
            cout<<result[i][j]<<" ";
        }
    }
    return 0; 
} 