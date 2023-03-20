#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll n;
    cin >> n;
    ll dp[6] = {1, 2, 4, 8, 16, 32};
    if (n <= 6) {
        cout << dp[n - 1] << "\n";
        return 0;
    }
    for (int i = 0; i < n - 6; i++) {
        int v = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4] + dp[5]) % ll(1e9 + 7);
        dp[0] = dp[1], dp[1] = dp[2], dp[2] = dp[3], dp[3] = dp[4],
        dp[4] = dp[5], dp[5] = v;
    }
    cout << dp[5] << "\n";
}