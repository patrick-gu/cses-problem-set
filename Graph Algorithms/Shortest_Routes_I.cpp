#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> es(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        // one way
        es[a].push_back({b, c});
    }
    vector<ll> dp(n, LONG_LONG_MAX);
    dp[0] = 0;
    set<pair<ll, int>> q;
    q.insert({0, 0});
    while (q.size()) {
        auto [b, x] = *q.begin();
        q.erase(q.begin());
        for (auto [e, c] : es[x]) {
            if (b + c < dp[e]) {
                auto it = q.find({dp[e], e});
                if (it != q.end()) q.erase(it);
                dp[e] = b + c;
                q.insert({b + c, e});
            }
        }
    }
    for (ll c : dp)
        cout << c << " ";
    cout << "\n";
}