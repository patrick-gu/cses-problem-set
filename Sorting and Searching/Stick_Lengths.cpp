#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cost(ll v, vector<ll>& ps) {
    ll acc = 0;
    for (ll p : ps)
        acc += abs(v - p);
    return acc;
}

int main(void) {
    ll n;
    cin >> n;
    vector<ll> ps(n);
    for (ll i = 0; i < n; i++)
        cin >> ps[i];
    ll lo = 0, hi = 1000000000;
    while (lo < hi) {
        ll mid1 = lo + (hi - lo) / 2;
        ll mid2 = mid1 + 1;
        ll c1 = cost(mid1, ps), c2 = cost(mid2, ps);
        if (c1 == c2) {
            lo = hi = mid1;
        } else if (c1 < c2) {
            hi = mid1;
        } else {
            lo = mid2;
        }
    }
    cout << cost(lo, ps) << "\n";
}