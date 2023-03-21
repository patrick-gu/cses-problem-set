#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> ans(n + 1, INT_MAX);
    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k > 0) {
            if (k % 10) ans[i] = min(ans[i], ans[i - (k % 10)] + 1);
            k /= 10;
        }
    }
    cout << ans[n] << "\n";
}