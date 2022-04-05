#include <bits/stdc++.h>
using namespace std;

class TwoSum {
    unordered_map<long,int> nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(const int number) {
        nums[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(const int value) {
        if (value > 200000 || value < -200000)
            return false;
    
        for (const  auto p : nums) {
            auto it = nums.find(value - p.first);
            if (nums.end() == nums.find(value - p.first))
                continue;
          
            
            if ((it->first != p.first) ||  (p.second>1))
                return true;
       
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