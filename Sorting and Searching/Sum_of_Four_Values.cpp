#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    ll n, x;
    cin >> n >> x;
    vector<ll> as(n);
    for (ll i = 0; i < n; i++)
        cin >> as[i];
    if (n < 4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    unordered_map<ll, pair<ll, ll>> start;
    start.insert({as[0] + as[1], {0, 1}});
    for (ll i = 2; i + 1 < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (start.find(x - as[i] - as[j]) != start.end()) {
                auto [a, b] = start[x - as[i] - as[j]];
                cout << (a + 1) << " " << (b + 1) << " " << (i + 1) << " "
                     << (j + 1) << "\n";
                return 0;
            }
        }
        for (ll j = 0; j < i; j++) {
            start.insert({as[j] + as[i], {j, i}});
        }
    }
    cout << "IMPOSSIBLE\n";
}