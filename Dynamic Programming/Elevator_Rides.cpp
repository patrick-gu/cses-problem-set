#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int n, x;
    cin >> n >> x;
    vector<ll> ws(n);
    for (int i = 0; i < n; i++)
        cin >> ws[i];
    vector<pair<ll, ll>> best(1 << n);
    best[0] = {1, 0};
    for (int i = 1; i < (1 << n); i++) {
        best[i] = {n + 1, 0};
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;
            auto [a, b] = best[i ^ (1 << j)];
            if (b + ws[j] <= x) {
                best[i] = min(best[i], {a, b + ws[j]});
            } else {
                best[i] = min(best[i], {a + 1, ws[j]});
            }
        }
    }
    cout << best.back().first << "\n";
}