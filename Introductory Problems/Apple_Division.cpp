#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    int n;
    cin >> n;
    vector<ll> ps(n);
    for (int i = 0; i < n; i++)
        cin >> ps[i];
    set<ll> pos;
    pos.insert(0);
    for (int p : ps) {
        set<ll> pos2;
        for (ll pp : pos) {
            pos2.insert(pp + p);
            pos2.insert(pp - p);
        }
        pos = pos2;
    }
    ll ans = LONG_LONG_MAX;
    for (ll pp : pos) {
        ans = min(ans, abs(pp));
    }
    cout << ans << "\n";
}