#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> efs(n), ebs(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c, a--, b--;
        efs[a].push_back({b, c});
        ebs[b].push_back({a, c});
    }
    vector<ll> dpf(n, 1e15), dpb(n, 1e15);
    dpf[0] = dpb[n - 1] = 0;
    set<pair<ll, int>> q;
    q.insert({0, 0});
    while (q.size()) {
        auto [b, x] = *q.begin();
        q.erase(q.begin());
        for (auto [e, c] : efs[x]) {
            if (b + c < dpf[e]) {
                auto it = q.find({dpf[e], e});
                if (it != q.end()) q.erase(it);
                dpf[e] = b + c;
                q.insert({dpf[e], e});
            }
        }
    }
    q.insert({0, n - 1});
    while (q.size()) {
        auto [b, x] = *q.begin();
        q.erase(q.begin());
        for (auto [e, c] : ebs[x]) {
            if (b + c < dpb[e]) {
                auto it = q.find({dpb[e], e});
                if (it != q.end()) q.erase(it);
                dpb[e] = b + c;
                q.insert({dpb[e], e});
            }
        }
    }
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        for (auto [e, c] : efs[i]) {
            ans = min(ans, dpf[i] + dpb[e] + c / 2);
        }
    }
    cout << ans << "\n";
}