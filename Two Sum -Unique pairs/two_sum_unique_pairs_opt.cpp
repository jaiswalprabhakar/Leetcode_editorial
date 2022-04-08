#include <bits/stdc++.h>
using namespace std;
  
int twoSum6(vector<int> &nums, int target) {
    set<pair<int, int>> unique_pairs;
    unordered_map<int, int> numbers;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        int num2 = nums[i];
        int num1 = target - num2;

        if (numbers.find(num1) != numbers.end() && numbers[num1] >= 1) {
            pair<int, int> p = make_pair(min(num1, num2), max(num1, num2));
            unique_pairs.insert(p);
        }

        ++numbers[num2];
    }

    return unique_pairs.size();
}
int main(){
    int n, target;
    cin>>n;
    vector<int> nums(n);
    int result;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cin>>target;
    result = twoSum6(nums, target);
    cout<<result;
    return 0;
}