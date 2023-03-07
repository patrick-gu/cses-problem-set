#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, q;
    cin >> n >> q;
    vector<int> es(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> es[i];

    int as[n + 1][21];

    as[1][0] = -1;

    for (int i = 0; i < n - 1; i++) {
        as[2 + i][0] = es[i];
    }

    for (int l = 1; l <= 20; l++) {
        for (int i = 1; i <= n; i++) {
            int t = as[i][l - 1];
            as[i][l] = (t == -1) ? -1 : (as[t][l - 1]);
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        while (k > 0) {
            if (x == -1) {
                break;
            }
            // cout << " " << (1 << (31 - __builtin_clz(k))) << "\n";
            // cout << " looking for " << x << " " << k << " "
            //  << (1 << (31 - __builtin_clz(k))) << "\n";
            x = as[x][31 - __builtin_clz(k)];
            k -= (1 << (31 - __builtin_clz(k)));
        }
        cout << x << "\n";
    }
}