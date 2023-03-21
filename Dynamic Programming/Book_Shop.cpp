#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    vector<int> hs(n), ss(n);
    for (int i = 0; i < n; i++)
        cin >> hs[i];
    for (int i = 0; i < n; i++)
        cin >> ss[i];
    vector<int> dp(x + 1);
    for (int i = 0; i < n; i++) {
        int h = hs[i], s = ss[i];
        for (int j = 0; j + h <= x; j++) {
            dp[j] = max(dp[j], s + dp[j + h]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}