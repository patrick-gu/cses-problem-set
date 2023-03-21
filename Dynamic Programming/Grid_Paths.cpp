#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int n;
    cin >> n;
    vector<string> gr(n);
    for (int i = 0; i < n; i++)
        cin >> gr[i];
    vector<vector<ll>> dp(n, vector<ll>(n));
    dp[0][0] = (gr[0][0] == '.');
    for (int x = 1; x < n; x++) {
        dp[0][x] = (gr[0][x] == '*') ? 0 : dp[0][x - 1];
    }
    for (int y = 1; y < n; y++) {
        dp[y][0] = (gr[y][0] == '*') ? 0 : dp[y - 1][0];
        for (int x = 1; x < n; x++) {
            dp[y][x] = (gr[y][x] == '*')
                           ? 0
                           : (dp[y - 1][x] + dp[y][x - 1]) % ll(1e9 + 7);
        }
    }
    cout << dp.back().back() << "\n";
}