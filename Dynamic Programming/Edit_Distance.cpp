#include <bits/stdc++.h>
using namespace std;

string n, m;
int dp[5001][5001];

int solve(int a, int b) {
    if (a == n.size()) return m.size() - b;
    if (b == m.size()) return n.size() - a;
    if (dp[a][b] != -1) return dp[a][b];
    if (n[a] == m[b]) {
        return dp[a][b] = solve(a + 1, b + 1);
    } else {
        return dp[a][b] = 1 + min(min(solve(a + 1, b + 1), solve(a + 1, b)),
                                  solve(a, b + 1));
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i <= 5000; i++)
        for (int j = 0; j <= 5000; j++)
            dp[i][j] = -1;
    cout << solve(0, 0) << "\n";
}