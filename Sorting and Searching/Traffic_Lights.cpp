#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    cin >> x >> n;
    multiset<int> sz;
    sz.insert(x);
    set<pair<int, int>> runs;
    runs.insert({0, x});
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto it = prev(runs.upper_bound({p, p + x + 1}));
        auto [start, end] = *it;
        runs.erase(it);
        sz.erase(sz.find(end - start));
        if (start < p) {
            runs.insert({start, p});
            sz.insert(p - start);
        }
        if (p < end) {
            runs.insert({p, end});
            sz.insert(end - (p));
        }
        cout << *sz.rbegin() << " ";
    }
    cout << "\n";
}