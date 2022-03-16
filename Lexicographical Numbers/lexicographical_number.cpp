 #include <bits/stdc++.h>
 using namespace std;

 void fun(vector<int>&res, int i, int n){
        if(i>n)            
            return;
        res.push_back(i);  
        fun(res,i*10,n);   
        if((i+1)%10!=0)    
            fun(res,i+1,n);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        fun(res,1,n);
        return res;
    }

    int main(){
        int n;
        cin>>n;
        vector<int> result(n);
        result = lexicalOrder(n);
        for(int i=0; i<n; i++){
            cout<<result[i]<<" ";
        }
    }