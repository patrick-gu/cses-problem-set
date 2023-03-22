#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    vector<int> dp(n + 1, 1e9 + 10);
    dp[0] = 0;
    for (int x : xs) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it != dp.end()) *it = x;
    }
    for (int i = n; i >= 0; i--) {
        if (dp[i] != (1e9 + 10)) {
            cout << i << "\n";
            break;
        }
    }
}