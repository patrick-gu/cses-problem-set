#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    multiset<int> ps;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        ps.insert(p);
    }
    int ans = 0;
    while (ps.size()) {
        int a = *ps.rbegin();
        ps.erase(prev(ps.end()));
        auto it = ps.upper_bound(x - a);
        if (it == ps.begin()) {
            ans++;
        } else {
            int b = *prev(it);
            ps.erase(prev(it));
            ans++;
        }
    }
    cout << ans << endl;
}