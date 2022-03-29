#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> x(10);
    x[2] = "abc";
    x[3] = "def";
    x[4] = "ghi";
    x[5] = "jkl";
    x[6] = "mno";
    x[7] = "pqrs";
    x[8] = "tuv";
    x[9] = "wxyz";
    if(digits.length() == 0){
        return {};
    }
    vector<string> ans;
    if(digits.length() == 1){
            int k = digits[0] - '0';
            string ss = x[k];
            for(int i=0;i<ss.length();i++){
                char c = ss[i];
                string s; s.push_back(c);
                ans.push_back(s);
            }
        }else if(digits.length() == 2){
        string s1 = x[digits[0] - '0'];
        string s2 = x[digits[1] - '0'];
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                string s;
                s.push_back(s1[i]);s.push_back(s2[j]);
                ans.push_back(s);
            }
        }
    }else if(digits.length() == 3){
        string s1 = x[digits[0] - '0'];
        string s2 = x[digits[1] - '0'];
        string s3 = x[digits[2] - '0'];
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                for(int k=0;k<s3.length();k++){
                string s;
                s.push_back(s1[i]);s.push_back(s2[j]);s.push_back(s3[k]);
                ans.push_back(s);
                }
            }
        }
    }else{
            string s1 = x[digits[0] - '0'];
        string s2 = x[digits[1] - '0'];
        string s3 = x[digits[2] - '0'];
        string s4 = x[digits[3] - '0'];
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                for(int k=0;k<s3.length();k++){
                    for(int l=0;l<s4.length();l++)
                    {
                        string s;
                        s.push_back(s1[i]);
                        s.push_back(s2[j]);
                        s.push_back(s3[k]);
                        s.push_back(s4[l]);
                        ans.push_back(s);
                    }
                }
            }
        }
    }
    
    return ans;
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