#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    int cs[n];
    for (int i = 0; i < n; i++)
        cin >> cs[i];
    vector<int> ans(x + 1, 1e9);
    ans[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (cs[j] <= i) ans[i] = min(ans[i], 1 + ans[i - cs[j]]);
        }
    }
    cout << ((ans[x] == 1e9) ? -1 : ans[x]) << "\n";
}