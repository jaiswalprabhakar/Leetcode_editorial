#include <iostream>
#include <vector>
using namespace std;

vector<int> viking_string(string s)
{
    int flip=0, sub=0;
    vector<int> result(2);
    for(int i=0; i< s.size(); i++){
        if(s[i] != s[i+1]){
            flip++;
            sub++;
            i++;
        }
    }
    result[0]= flip;
    result[1]= sub;
    return result;
}

int main()
{
    string str;
    cin>>str;
    vector<int> temp = viking_string(str);
    cout<< temp[0] << "\n" <<temp[1];
    return 0;
}