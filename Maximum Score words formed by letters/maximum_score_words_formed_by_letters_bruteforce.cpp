#include <bits/stdc++.h>
using namespace std;

int helper(vector<string>& words, int* fmap, vector<int>& score, int idx){
        
    if(idx == words.size()){ 
        return 0;
    }        
    
    int noContribScore = helper(words, fmap, score, idx+1); 
    
    string currentWord = words[idx];
    int currentWordScore = 0;
    
    bool can_we_use_currentWord = true;
    
    for(auto x : currentWord){
        char currentChar = x; 
        
        
        if(fmap[currentChar - 'a'] <= 0){
            can_we_use_currentWord = false;
        }
        fmap[currentChar - 'a'] -=1; 
        currentWordScore += score[currentChar-'a']; 
        
    }
    
    int contribScore = 0;
    
    if(can_we_use_currentWord == true){ 
        contribScore = currentWordScore + helper(words, fmap, score, idx+1);
    }
    
   
    
    for(auto x : currentWord){
        fmap[x - 'a']+=1;
    }
    
    return max(contribScore, noContribScore);
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    int fmap[26] = {0};
    
    for(auto x : letters){
        fmap[x-'a']++; 
    }
    
    return helper(words, fmap, score, 0);
}

int main(){
    int n,m;
    cin>>n;
    vector<string> words(n);
    vector<int> score(26);
    for(int i=0; i<n; i++){
        cin>>words[i];
    }
    cin>>m;
    vector<char> letter(m);
    for(int i=0; i<m; i++){
        cin>>letter[i];
    }
    for(int i=0; i<26; i++){
        cin>>score[i];
    }
    cout<<maxScoreWords(words, letter, score);
}