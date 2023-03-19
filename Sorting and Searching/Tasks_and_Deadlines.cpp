#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> as(n), ds(n);
    for (ll i = 0; i < n; i++)
        cin >> as[i] >> ds[i];
    sort(as.begin(), as.end());

    ll t = 0, cost = 0;
    for (ll a : as) {
        t += a;
        cost += t;
    }
    cout << accumulate(ds.begin(), ds.end(), -cost) << "\n";
}