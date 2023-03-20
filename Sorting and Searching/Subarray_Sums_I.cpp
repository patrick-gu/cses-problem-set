#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    ll n, x;
    cin >> n >> x;
    vector<ll> as(n);
    for (ll i = 0; i < n; i++)
        cin >> as[i];
    ll hi = 0, cur = 0, ans = 0;
    for (ll lo = 0; lo < n; lo++) {
        while (hi < n && cur < x)
            cur += as[hi++];
        if (cur == x) ans++;
        cur -= as[lo];
    }
    cout << ans << "\n";
}