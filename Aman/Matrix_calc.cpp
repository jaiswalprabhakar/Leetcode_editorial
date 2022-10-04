#include <bits/stdc++.h>
using namespace std;

int calculate(int a, int b, char sym){
    if(sym == '+'){
        return a+b;
    }
    else if(sym == '-'){
        return a-b;
    }
    else if(sym == '*'){
        return a*b;
    }
    else {
        return a/b;
    }
}
int main(){
    int m, n;
    cin >>m>>n;
    int arr1[m][n], arr2[m][n], result[m][n];
    char operand[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr1[i][j];
        }
    } 
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr2[i][j];
        }
    } 
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>operand[i][j];
        }
    } 
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            result[i][j] = calculate(arr1[i][j], arr2[i][j], operand[i][j]);
        }
    } 

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
           cout<<result[i][j]<<" ";
        }
        cout<<endl;
    } 
    
}