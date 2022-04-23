#include <bits/stdc++.h>
using namespace std;

int getLeft(vector<int> &height , int i){
	int longest = 0;
	for(int b = 0 ; b < i ; b++){
		longest = max(longest , height[b]);
	}
	return longest;
}
int getRight(vector<int> &height , int i){
	int longest = 0;
	for(int b = i + 1 ; b < height.size() ; b++){
		longest = max(longest , height[b]);
	}
	return longest;
}
int trap(vector<int> &height){
	int n = height.size();
	int trapped = 0;
	for(int i = 0 ; i < n ; i++){
		int left_max_bar = getLeft(height , i);
		int right_max_bar = getRight(height , i);

		int current_water_hold = min(left_max_bar , right_max_bar) - height[i];
		trapped += max(0 , current_water_hold);
	}

	return trapped;
}
int main(){
    int n, result;
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    result = trap(height);
    cout<<result;
    return 0;

}