#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    ll n, x;
    cin >> n >> x;
    // unordered_map is subject to hash collision
    map<ll, ll> as;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (as.find(x - a) != as.end()) {
            cout << as[x - a] << " " << (i + 1) << "\n";
            return 0;
        }
        as.insert({a, i + 1});
    }
    cout << "IMPOSSIBLE\n";
}