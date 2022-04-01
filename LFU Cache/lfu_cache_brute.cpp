#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        int total = pow(k, n);
        string res = string(n, '0'); 
        unordered_set<string> visited;
        visited.insert(res);
        helper(res, n, k, total, visited);
        return res;
    }
    
    bool helper(string& res, int n, int k, int total, unordered_set<string>& visited){
        if(visited.size() == total) return true;
        string cur = res.substr(res.size() - n + 1);
        for(int i = 0; i < k; i++){
            string next = cur + to_string(i);
            if(visited.count(next)) continue;
            visited.insert(next);
            res.push_back(i + '0');
            if(helper(res, n, k, total, visited)) return true;
            res.pop_back();
            visited.erase(next);
        }
        return false;
    }
};

int main() { 
    int n, k;
    string result;
    cin>>n;
    cin>>k;

    Solution *obj = new Solution();
    result = obj->crackSafe(n,k);
    cout<<result;
    return 0; 
} 