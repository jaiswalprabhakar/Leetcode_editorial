#include<bits/stdc++.h>
using namespace std;

class Cashier {
public:
    // 'count' will store the serial no. of a customer
    int count,n,discount;
    
    
    unordered_map<int,int>m;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        
        // initialise the values
        count=0;
        this->n=n;
        this->discount=discount;
        
        // populate the unordered map 
        for(int i=0;i<products.size();i++) {
            m[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        // as a new customer comes
        count++;
        
        // 'total' will be the actual bill
        double total=0;
        
        // calculate the total bill
        for(int i=0;i<product.size();i++) {
            total+=(double)(amount[i]*m[product[i]]);
        }
        
        // if he/she is the nth customer then give the discount
        if(count%n==0) {
            total=total*((100-(double)discount)/100);
        }
        
        // finally return the bill
        return total;
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