#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, result=0, temp1;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        cin>>temp1;
        arr.push_back(temp1);
    }
    sort(arr.begin(), arr.end());
    queue<int> temp;
    result += abs(arr.front() - arr.back());
    temp.push(abs(arr.front() - arr.back()));
    arr.erase(arr.begin());
    arr.pop_back(); 
    while(arr.size() >1){
        if(temp.front()<arr.back()){
            result += abs(arr.front() - arr.back());
            temp.push(abs(arr.front() - arr.back()));
            arr.erase(arr.begin());
            arr.pop_back(); 
            
        }
        else{
            result += abs(arr.front() - temp.front());
            temp.pop();
            arr.erase(arr.begin());
        }
    }
    cout<<result;
}