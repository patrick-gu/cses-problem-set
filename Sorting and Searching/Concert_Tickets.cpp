#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    multiset<int> hs;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        hs.insert(h);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto it = hs.upper_bound(t);
        if (it == hs.begin()) {
            cout << "-1\n";
        } else {
            cout << *prev(it) << "\n";
            hs.erase(prev(it));
        }
    }
}