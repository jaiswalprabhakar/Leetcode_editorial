class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i =0; i<b.size(); i++){
            if(a[i]== b[i]){
                result += a[i];
            }
            else
                break;
        }
        return result;
    }
};