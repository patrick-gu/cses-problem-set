#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll llpow(ll a, ll b) {
    if (b == 0) return 1;
    ll v = llpow(a, b / 2);
    return (v * v) * ((b % 2) ? a : 1);
}

int main(void) {
    int q;
    cin >> q;
    vector<ll> cutoffs;
    cutoffs.push_back(0);
    for (ll i = 1; i <= 17; i++) {
        cutoffs.push_back(cutoffs.back() + i * 9 * llpow(10, i - 1));
    }
    while (q--) {
        ll k;
        cin >> k;
        k--;
        ll i = upper_bound(cutoffs.begin(), cutoffs.end(), k) -
               cutoffs.begin() - 1;
        ll n = (k - cutoffs[i]) / (i + 1) + llpow(10, i);
        ll at = (k - cutoffs[i]) % (i + 1);
        string s = to_string(n);
        cout << s[at] << "\n";
    }
}