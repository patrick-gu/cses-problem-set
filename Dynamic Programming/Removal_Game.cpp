#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b, vector<ll>& xs, vector<vector<ll>>& dp) {
    if (b < a) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    return dp[a][b] = max(xs[a] - solve(a + 1, b, xs, dp),
                          xs[b] - solve(a, b - 1, xs, dp));
}

int main(void) {
    ll n;
    cin >> n;
    vector<ll> xs(n);
    for (ll i = 0; i < n; i++)
        cin >> xs[i];
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    ll diff = solve(0, n - 1, xs, dp);
    cout << (accumulate(xs.begin(), xs.end(), diff) / 2LL) << "\n";
}