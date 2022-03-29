#include <bits/stdc++.h>
using namespace std;

const vector<string> pad = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> result;
    result.push_back("");
    
    for(auto digit: digits) {
        vector<string> tmp;
        for(auto candidate: pad[digit - '0']) {
            for(auto s: result) {
                tmp.push_back(s + candidate);
            }
        }
        result.swap(tmp);
    }
    return result;
}
int main() { 
    string digits;
    cin>>digits;
    vector<string> result;
    result = letterCombinations(digits);
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0; 
} 