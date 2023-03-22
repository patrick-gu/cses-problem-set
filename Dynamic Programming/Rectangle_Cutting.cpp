#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int solve(int a, int b) {
    if (a == b) return 0;
    if (a > b) swap(a, b);
    if (dp[a][b] != -1) return dp[a][b];
    int ans = INT_MAX;
    for (int i = 1; i + 1 <= a; i++)
        ans = min(ans, 1 + solve(i, b) + solve(a - i, b));
    for (int i = 1; i + 1 <= b; i++)
        ans = min(ans, 1 + solve(a, i) + solve(a, b - i));
    return dp[a][b] = ans;
}

int main(void) {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= 500; i++)
        for (int j = 0; j <= 500; j++)
            dp[i][j] = -1;
    cout << solve(a, b) << "\n";
}
