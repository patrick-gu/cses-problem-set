#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> as(n);
    for (ll i = 0; i < n; i++)
        cin >> as[i];
    ll cur = 0, ans = 0;
    vector<ll> cnt(n);
    cnt[0] = 1;
    for (ll a : as) {
        cur += a;
        ll m = ((cur % n) + n) % n;
        ans += cnt[m]++;
    }
    cout << ans << "\n";
}