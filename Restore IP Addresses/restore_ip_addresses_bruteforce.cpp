#include <bits/stdc++.h>
using namespace std;

set<string> ips;
    
void eval(int i,int j,int k,string& s){
    string ss = "";
    int n = s.length();
    vector<int>test = {-1,i,j,k,n-1};
    for(int x=1;x<5;x++){
        int cur = 0;
        for(int l=test[x-1]+1;l<=test[x];l++){
            cur*=10;
            cur+=s[l]-'0';
        }
        if(cur<=255){
            string tf = s.substr(test[x-1]+1,test[x]-test[x-1]);
            if(tf!=to_string(cur))return;
            ss+=tf;
            if(x<4)ss+=".";
        }
        else return;
    }
    ips.insert(ss);
}

vector<string> restoreIpAddresses(string s) {
    if(s.length()>12)return {};
    int n = s.length();
    for(int i = 0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n-1;k++){
                    eval(i,j,k,s);
            }
        }
    }
    vector<string> ans(ips.begin(),ips.end());
    return ans;
}

int main(){
      string s;
      cin>>s;
      vector<string> res;
      res = restoreIpAddresses(s);
      for(int i=0; i< res.size(); i++){
          cout<<res[i]<<" ";
      }
  }