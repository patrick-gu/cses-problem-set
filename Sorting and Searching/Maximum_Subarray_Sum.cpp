#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    ll cur = 0, best = LONG_LONG_MIN;
    for (int i = 0; i < n; i++) {
        cur += (ll)xs[i];
        best = max(best, cur);
        if (cur < 0) {
            cur = 0;
        }
    }
    cout << best << endl;
}