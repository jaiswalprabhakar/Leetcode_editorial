#include <bits/stdc++.h>
using namespace std;

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    int ans=0;
    vector<int> cnt(26);
    fill(cnt.begin(),cnt.end(),0);
    for(auto x:letters)cnt[x-'a']++;
    int n=words.size();
    int lim=(1<<n);
    for(int mask=0;mask<lim;mask++){
        int res=0;
        vector<int> tcnt=cnt;
        int flag=0;
        for(int pos=n-1;pos>=0;pos--){
            if((mask>>pos)&1){
                string s=words[pos];
                for(int i=0;i<s.size();i++){
                    tcnt[s[i]-'a']--;
                    if(tcnt[s[i]-'a']<0){
                        flag=1;
                        break;
                    }
                    else res+=score[s[i]-'a'];
                }
            }
            if(flag==1)break;
        }
        if(flag==0)ans=max(ans,res);
    }
    return ans;
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