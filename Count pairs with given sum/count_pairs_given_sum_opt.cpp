#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int sum) {
        unordered_map<int, int> m;
        // Store counts of all elements in map m
        for (int i = 0; i < n; i++)
            m[arr[i]]++;
        int twice_count = 0;
        // iterate through each element and increment the
        // count (Notice that every pair is counted twice)
        for (int i = 0; i < n; i++) {
            twice_count += m[sum - arr[i]];
            // if (arr[i], arr[i]) pair satisfies the condition,
            // then we need to ensure that the count is
            // decreased by one such that the (arr[i], arr[i])
            // pair is not considered
            if (sum - arr[i] == arr[i])
                twice_count--;
        }
    
        // return the half of twice_count
        return twice_count / 2;
    }
};

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin>>k;
    Solution ob;
    auto ans = ob.getPairsCount(arr, n, k);
    cout << ans << "\n";
    return 0;
}  