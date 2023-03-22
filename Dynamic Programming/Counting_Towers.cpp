#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(void) {
    // Let dp(a, b) denote the number of ways to make a tower
    // with first column height a and second column height b.
    // We have z(a) = dp(a, a) = (sum i=0 to a-1 of dp(i, i))
    // + (sum i=0 to a-1 of dp(i, a))
    // Let y(a) = (sum i=0 to a-1 of dp(i, a))
    // We have y(a + 1) = 3 * y(a) + dp(a, a)
    int t;
    cin >> t;
    vector<ll> ans;
    ans.push_back(0);
    ll x = 1, y = 1;
    for (int i = 0; i < 1000000; i++) {
        ll z = (x + y) % MOD;
        ans.push_back(z);
        y = (y * 3 + z) % MOD;
        x = (x + z) % MOD;
    }
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
}