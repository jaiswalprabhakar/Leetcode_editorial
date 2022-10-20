#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 998244353;
const int MAX = (int)1e6 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int temp = 0, num;
    cin >> num;
    int integer[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char *roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    string ans;

    for (int i = 12; i >= 0; i--)
    {
        temp = num / integer[i];
        cout << "temp" << temp << "\n";
        for (int j = 0; j < temp; j++)
            ans += roman[i];
        cout << "ans" << ans << "\n";
        num %= integer[i];
        cout << "num" << num << "\n";
    }
    cout << ans;
    return 0;
}