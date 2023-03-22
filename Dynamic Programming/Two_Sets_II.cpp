#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int n;
    cin >> n;
    int k = n * (n - 1) / 2;
    vector<ll> dp(k + 1), dpswp(k + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            ll v = 0;
            if (abs(j - i) <= k) v += dp[abs(j - i)];
            if (j + i <= k) v += dp[j + i];
            if (v >= 2LL * ll(1e9 + 7)) v -= 2LL * ll(1e9 + 7);
            dpswp[j] = v;
        }
        swap(dp, dpswp);
    }
    cout << dp[0] / 2 << "\n";
}