#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count(vector<ll>& xs, ll m) {
    ll cur = 0, ans = 1;
    for (ll x : xs) {
        if (cur + x > m) {
            cur = x, ans++;
        } else {
            cur += x;
        }
    }
    return ans;
}

int main(void) {
    ll n, k;
    cin >> n >> k;
    vector<ll> xs(n);
    for (ll i = 0; i < n; i++)
        cin >> xs[i];
    // must have at least max element
    ll lo = *max_element(xs.begin(), xs.end()),
       hi = accumulate(xs.begin(), xs.end(), 0LL);
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (count(xs, mid) <= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
}