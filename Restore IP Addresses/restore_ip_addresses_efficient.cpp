#include <bits/stdc++.h>
using namespace std;

vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    for (int a = 1; a <= 3; ++a) {
      for (int b = 1; b <= 3; ++b) {
        for (int c = 1; c <= 3; ++c) {
          int d = s.size() - a - b - c;
          
          if (1 <= d && d <= 3 && 
            (1 == a || '0' != s[0        ] && (3 != a || 0 < memcmp("256", &s[0        ], 3))) &&
            (1 == b || '0' != s[a        ] && (3 != b || 0 < memcmp("256", &s[a        ], 3))) &&
            (1 == c || '0' != s[a + b    ] && (3 != c || 0 < memcmp("256", &s[a + b    ], 3))) &&
            (1 == d || '0' != s[a + b + c] && (3 != d || 0 < memcmp("256", &s[a + b + c], 3)))) 
          {
            ret.emplace_back(s.substr(0, a) + "." + s.substr(a, b) + "." + s.substr(a + b, c) + "." + s.substr(a + b + c));
          }
        }
      }
    }
  
    return ret;
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