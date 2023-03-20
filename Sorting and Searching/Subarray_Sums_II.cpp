#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll n, x;
    cin >> n >> x;
    vector<ll> as(n);
    for (ll i = 0; i < n; i++)
        cin >> as[i];
    unordered_map<ll, ll> before;
    before[0] = 1;
    ll cur = 0, ans = 0;
    for (ll a : as) {
        cur += a;
        ans += before[cur - x];
        before[cur]++;
    }
    cout << ans << "\n";
}