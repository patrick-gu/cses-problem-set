#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dp(n, vector<ll>(n, 1e15));
    // accounts for if a = b
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c, a--, b--;
        dp[a][b] = min(c, dp[a][b]);
        dp[b][a] = min(c, dp[b][a]);
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    while (q--) {
        int a, b;
        cin >> a >> b, a--, b--;
        cout << ((dp[a][b] >= 1e15) ? -1LL : dp[a][b]) << "\n";
    }
}