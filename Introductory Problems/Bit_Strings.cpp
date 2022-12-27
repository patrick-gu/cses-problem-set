#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll powmod(ll n, ll e, ll m) {
    if (e == 0) return 1;
    if (e == 1) return n;
    if (e % 2) {
        ll a = powmod(n, e / 2, m);
        return (((a * a) % m) * n) % m;
    } else {
        ll a = powmod(n, e / 2, m);
        return (a * a) % m;
    }
}

int main(void) {
    ll n;
    cin >> n;
    cout << powmod(2, n, 1000000007) << "\n";
}
