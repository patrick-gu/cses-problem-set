#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, t;
ll ks[200009];

ll add_overflow(ll a, ll b) {
    if (a + b < 0) return LONG_LONG_MAX;
    return a + b;
}

ll calc(ll a) {
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        // careful of overflow here
        ans = add_overflow(ans, a / ks[i]);
    }
    return ans;
}

int main(void) {
    cin >> n >> t;
    for (ll i = 0; i < n; i++)
        cin >> ks[i];
    ll lo = 0, hi = 1e18 + 3;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (calc(mid) >= t) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
}