#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> xs(n), is(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x, x--, xs[i] = x, is[x] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (is[i] < is[i - 1]) ans++;
    while (m--) {
        int a, b;
        cin >> a >> b, a--, b--;
        if (a != b) {
            int xa = xs[a], xb = xs[b];
            if (xa > xb) {
                swap(xa, xb);
                swap(a, b);
            }
            if (xa + 1 == xb) {
                if (xa != 0 && is[xa] < is[xa - 1]) ans--;
                if (is[xa] > is[xa + 1]) ans--;
                if (xb != n - 1 && is[xb + 1] < is[xb]) ans--;
            } else {
                if (xa != 0 && is[xa] < is[xa - 1]) ans--;
                if (xa != n - 1 && is[xa + 1] < is[xa]) ans--;
                if (xb != 0 && is[xb] < is[xb - 1]) ans--;
                if (xb != n - 1 && is[xb + 1] < is[xb]) ans--;
            }
            is[xb] = a, is[xa] = b;
            swap(xs[a], xs[b]);
            if (xa + 1 == xb) {
                if (xa != 0 && is[xa] < is[xa - 1]) ans++;
                if (is[xa] > is[xa + 1]) ans++;
                if (xb != n - 1 && is[xb + 1] < is[xb]) ans++;
            } else {
                if (xa != 0 && is[xa] < is[xa - 1]) ans++;
                if (xa != n - 1 && is[xa + 1] < is[xa]) ans++;
                if (xb != 0 && is[xb] < is[xb - 1]) ans++;
                if (xb != n - 1 && is[xb + 1] < is[xb]) ans++;
            }
        }
        cout << ans << "\n";
    }
}