#include <bits/stdc++.h>
using namespace std;
  
bool isSumEqual(string firstWord, string secondWord, string targetWord) {

    std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	
	long long int  sum1 = 0;
	long long int sum2 = 0;
	long long int sum3 = 0;
	for (int i = 0 ; i < firstWord.length(); i++) {
		v1.push_back(firstWord[i] - 'a');
	}
	for (int i = 0 ; i < secondWord.length(); i++) {
		v2.push_back(secondWord[i] - 'a');
	}
	for (int i = 0 ; i < targetWord.length(); i++) {
		v3.push_back(targetWord[i] - 'a');
	}
	int j = 0;
	int k = 0;
	int l = 0;
	for (int i = v1.size() - 1; i >= 0; i--) {
		sum1 += v1[i] * pow(10, j);
		j++;
	}
	for (int i = v2.size() - 1; i >= 0; i--) {
		sum2 += v2[i] * pow(10, k);
		k++;
	}
	for (int i = v3.size() - 1; i >= 0; i--) {
		sum3 += v3[i] * pow(10, l);
		l++;
	}
	if (sum1 + sum2 == sum3)
        return true;
	else 
        return false;
}
int main() { 
    string first, second, target;
    cin>>first>>second>>target;
    cout<<isSumEqual(first,second,target);
    return 0; 
} 