#include <bits/stdc++.h>
using namespace std;

class TwoSum {
private:
    vector<int> ourSum;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        ourSum.reserve(1000);
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ourSum.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (ourSum.empty()) return false;
        sort(ourSum.begin(), ourSum.end()); // Only sort when we need to find a value
        int i{}, j{ourSum.size() - 1}; // Two pointer method, to beginning and end of the vector
        while (i != j) {
            if (ourSum[j] + ourSum[i] > value) j--;
            else if (ourSum[j] + ourSum[i] < value) i++;
            else return true;
        }
        return false;
    }
};

int main() { 
    int n, nums, value, temp;
    cin>>n;
    string task;
	  vector<bool> result;
    TwoSum *obj = new TwoSum();
    while(n--){
        cin>>task;
        if(task == "add"){
            cin>>nums;
            obj->add(nums);
        }
        else if(task=="find"){
            cin>>value;
            temp = obj->find(value);
			      result.push_back(temp);
        }
    }
	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<" ";
	}
    return 0; 
} 