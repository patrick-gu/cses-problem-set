#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 1e9 + 7;

ll mod1(ll v) {
    return (v >= M) ? (v - M) : v;
}

int main(void) {
    int n, x;
    cin >> n >> x;
    vector<int> cs(n);
    for (int i = 0; i < n; i++)
        cin >> cs[i];
    vector<int> ans(x + 1);
    ans[0] = 1;
    for (int c : cs) {
        for (int i = 0; i < x; i++) {
            if (i + c <= x) {
                ans[i + c] = int(mod1(ll(ans[i + c]) + ll(ans[i])));
            }
        }
    }
    cout << ans[x] << "\n";
}