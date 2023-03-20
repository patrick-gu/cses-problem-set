#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> as(n);
    for (ll i = 0; i < n; i++)
        cin >> as[i].first, as[i].second = i;
    sort(as.begin(), as.end());
    for (ll i = 0; i + 2 < n; i++) {
        ll j = i + 1, k = n - 1;
        while (j < k) {
            if (as[i].first + as[j].first + as[k].first == x) {
                cout << (as[i].second + 1) << " " << (as[j].second + 1) << " "
                     << (as[k].second + 1) << "\n";
                return 0;
            } else if (as[i].first + as[j].first + as[k].first < x) {
                j++;
            } else {
                k--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}