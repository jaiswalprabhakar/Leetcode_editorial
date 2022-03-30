#include <bits/stdc++.h>
using namespace std;
int countCharacters(vector<string>& words, string chars) {    
    for (auto& str : words)
        sort(str.begin(),str.end());
    sort(chars.begin(),chars.end());
    int length = 0;
    for (auto& str : words){
        auto it_s = str.begin();
        int str_length = str.size();
        for (auto it_c = chars.begin(); it_c != chars.end(); it_c++){
            if (*it_c == *it_s){
                it_s = str.erase(it_s);
                if (str.empty()){
                    length += str_length;
                    break;
                }
            }
            else if (*it_c > *it_s)
                break;
        }
    }
    return length;
}
int main() { 
    string chars;
    int n, result;
    cin>>n;
    vector<string> words(n);
    for(int i=0; i<n; i++){
        cin>>words[i];
    }
    cin>>chars;
    result = countCharacters(words, chars);
    cout<<result;
    return 0; 
} 