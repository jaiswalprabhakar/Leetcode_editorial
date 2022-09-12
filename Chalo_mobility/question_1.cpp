#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX = 1e5 + 5, MOD = 1e9 + 7;

ll dp[MAX][10];

ll solve(ll i, ll p, ll &n, ll &k, ll &x){
    if(i == n)return 1;

    ll &ans = dp[i][p];
    if(ans != -1)return ans;
    ans = 0;

    for(int j = 1; j <= k; j++){

        if(j != p){
            ans += solve(i + 1, j, n, k, x);
            ans %= MOD;
        }
    }

    if(p == x)ans += solve(i + 1, p, n, k, x);

    return ans;
}
int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ll t;
    cin >> t;
    while(t--){
        memset(&dp, -1, sizeof dp);
        ll n, k, x;
        cin >> n >> k >> x;

        ll ans = 0;
        for(int i = 1; i <= k; i++){

            ans += solve(1, i, n, k, x);
            ans %= MOD;
        }

        cout << ans << endl;


    }


    return 0;
}