#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ll n;
    cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll a = (k * k) * (k * k - 1) / 2;
        ll b = -4 * k * k + 12 * k - 8;
        cout << (a + b) << "\n";
    }
}
