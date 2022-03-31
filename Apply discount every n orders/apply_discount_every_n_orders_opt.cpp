#include<bits/stdc++.h>
using namespace std;

class Cashier {
public:
    map<int, int> tags;
    int cnt, mod;
    double pct;
    
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt = 0, mod = n, pct = (100.0 - discount) / 100.0;
        for(int i=0; i<products.size(); ++i){
            tags[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        double ans(0.0);
        for(int i=0; i<product.size(); ++i){
            ans += tags[product[i]] * amount[i];
        }
        return cnt % mod ? ans : ans * pct;
    }
};

int main(){
    int n, discount;
    cin>>n>>discount;
    vector<int> products, prices;
    int x;
    cin>>x;
    for(int i=0; i<x; i++){
        int temp;
        cin>>temp;
        products.push_back(temp);
    }
    for(int i=0; i<x; i++){
        int temp;
        cin>>temp;
        prices.push_back(temp);
    }
    Cashier *obj = new Cashier(n, discount, products, prices);
    int q;
    cin>>q;
    while(q--){
        vector<int> prod, amt;
        cin>>x;
        for(int i=0; i<x; i++){
            int temp;
            cin>>temp;
            prod.push_back(temp);
        }
        for(int i=0; i<x; i++){
            int temp;
            cin>>temp;
            amt.push_back(temp);
        }
        double ans = obj->getBill(prod, amt);
        cout<<ans<<endl;
    }
}