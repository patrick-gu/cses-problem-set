#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> esf(n), esb(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        a--, b--;
        x = -x;
        esf[a].push_back({b, x});
        esb[b].push_back({a, x});
    }
    vector<ll> dp(n, 1e15);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[j] != 1e15)
                for (auto [e, c] : esf[j]) {
                    dp[e] = min(dp[e], dp[j] + c);
                }
        }
    }
    vector<bool> reachable(n);
    reachable[n - 1] = true;
    deque<int> q;
    q.push_back(n - 1);
    while (q.size()) {
        int x = q.front();
        q.pop_front();
        for (auto [e, c] : esb[x]) {
            if (!reachable[e]) {
                reachable[e] = true;
                q.push_back(e);
            }
        }
    }
    for (int j = 0; j < n; j++) {
        if (dp[j] != 1e15)
            for (auto [e, c] : esf[j]) {
                if ((dp[e] > dp[j] + c) && reachable[e]) {
                    cout << "-1\n";
                    return 0;
                }
            }
    }
    cout << -dp[n - 1] << "\n";
}