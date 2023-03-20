#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    vector<int> vs = xs;
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    for (int& x : xs)
        x = lower_bound(vs.begin(), vs.end(), x) - vs.begin();

    int sz = 1;
    while (sz < vs.size() + 1)
        sz *= 2;
    vector<int> seg(sz * 2);
    function<void(int, int, int, int, int, int)> update =
        [&seg, &update](int a, int b, int v, int p, int l, int r) {
            if (r < a || b < l) return;
            if (a <= l && r <= b) {
                seg[p] = v;
                return;
            }
            int m = (l + r) / 2;
            update(a, b, v, p * 2, l, m);
            update(a, b, v, p * 2 + 1, m + 1, r);
        };

    cout << "0";
    update(xs[0] + 1, sz - 1, 1, 1, 0, sz - 1);
    for (int i = 1; i < xs.size(); i++) {
        int o = 0, cur = sz + xs[i];
        while (cur > 0) {
            o = max(o, seg[cur]);
            cur /= 2;
        }
        cout << " " << o;
        update(xs[i] + 1, sz - 1, i + 1, 1, 0, sz - 1);
    }
    cout << "\n";
}