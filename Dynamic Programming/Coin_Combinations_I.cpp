#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    int cs[n];
    for (int i = 0; i < n; i++)
        cin >> cs[i];
    vector<int> ans(x + 1, 0);
    ans[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (cs[j] <= i) {
                ans[i] += ans[i - cs[j]];
                ans[i] %= int(1e9 + 7);
            }
        }
    }
    cout << ans[x] << "\n";
}