#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll n, m;

ll cnt(ll v, ll s, ll e) {
    if (v == 0) {
        // because some inputs may be invalid
        return abs(s - e) <= 1;
    }
    if (m == 1) return 1;
    vector<ll> dp(m + 1);
    dp[s] = 1;
    for (ll i = 0; i < v; i++) {
        vector<ll> dp2 = dp;
        dp2[1] = (dp2[1] + dp[2]) % MOD;
        dp2[m] = (dp2[m] + dp[m - 1]) % MOD;
        for (ll j = 2; j < m; j++) {
            dp2[j] = (dp2[j] + dp[j - 1] + dp[j + 1]) % MOD;
        }
        dp = dp2;
    }
    return (dp[e] + (e == 1LL ? 0LL : dp[e - 1]) + (e == m ? 0LL : dp[e + 1])) %
           MOD;
}

ll cnt2(ll v, ll s) {
    if (v == 0) return 1;
    if (m == 1) return 1;
    vector<ll> dp(m + 1);
    dp[s] = 1;
    for (ll i = 0; i < v; i++) {
        vector<ll> dp2 = dp;
        dp2[1] = (dp2[1] + dp[2]) % MOD;
        dp2[m] = (dp2[m] + dp[m - 1]) % MOD;
        for (ll j = 2; j < m; j++) {
            dp2[j] = (dp2[j] + dp[j - 1] + dp[j + 1]) % MOD;
        }
        dp = dp2;
    }
    return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
}

ll cnt3(ll v) {
    if (v == 0) return 1;
    if (m == 1) return 1;
    vector<ll> dp(m + 1, 1);
    dp[0] = 0;
    for (ll i = 1; i < v; i++) {
        vector<ll> dp2 = dp;
        dp2[1] = (dp2[1] + dp[2]) % MOD;
        dp2[m] = (dp2[m] + dp[m - 1]) % MOD;
        for (ll j = 2; j < m; j++) {
            dp2[j] = (dp2[j] + dp[j - 1] + dp[j + 1]) % MOD;
        }
        dp = dp2;
    }
    return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
}

int main(void) {
    cin >> n >> m;
    vector<ll> xs(n);
    for (ll i = 0; i < n; i++)
        cin >> xs[i];

    vector<ll> nzs;
    for (ll i = 0; i < n; i++) {
        if (xs[i]) nzs.push_back(i);
    }
    if (nzs.size() == 0) {
        cout << cnt3(n) << "\n";
        return 0;
    }
    ll ans =
        (cnt2(nzs[0], xs[nzs[0]]) * cnt2(n - 1 - nzs.back(), xs[nzs.back()])) %
        MOD;
    for (ll i = 0; i + 1 < nzs.size(); i++) {
        ans *= cnt(nzs[i + 1] - nzs[i] - 1, xs[nzs[i]], xs[nzs[i + 1]]);
        ans %= MOD;
    }
    cout << ans << "\n";
}