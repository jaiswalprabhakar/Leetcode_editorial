class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n= nums.size();
        int i=0;
        while(n--){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
                //n--;
            }
            else 
                i++;
        }
        return nums.size();
    }
};