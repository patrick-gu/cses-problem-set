#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll n, k;
    cin >> n >> k;
    ll xs[n];
    for (ll i = 0; i < n; i++)
        cin >> xs[i];
    ll lo = 0, hi = 0, ans = 0;
    unordered_map<ll, ll> vs;
    for (; lo < n; lo++) {
        while (hi < n && (vs.size() < k || vs.find(xs[hi]) != vs.end()))
            vs[xs[hi++]]++;
        ans += hi - lo;
        vs[xs[lo]]--;
        if (vs[xs[lo]] == 0) vs.erase(xs[lo]);
    }
    cout << ans << "\n";
}