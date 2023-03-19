#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    int n;
    cin >> n;
    vector<ll> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    sort(xs.begin(), xs.end());
    if (xs[0] != 1) {
        cout << "1\n";
        return 0;
    }
    ll m = 1;
    for (int i = 1; i < n; i++) {
        ll a = xs[i];
        if (a > m + 1) {
            cout << (m + 1) << "\n";
            return 0;
        }
        m += a;
    }
    cout << (m + 1) << "\n";
}