#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<tuple<int, bool, int>, ll> dp;

ll solve(string& n, int idx, bool f, int last) {
    if (idx == n.size()) return 1;
    if (dp.find({idx, f, last}) != dp.end()) return dp[{idx, f, last}];
    int d = n[idx] - '0';
    ll ans = 0;
    if (f) {
        for (int i = 0; i <= d; i++) {
            if (i == last) continue;
            ans += solve(n, idx + 1, i == d, (last == -1 && i == 0) ? -1 : i);
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            if (i == last) continue;
            ans += solve(n, idx + 1, false, (last == -1 && i == 0) ? -1 : i);
        }
    }
    return dp[{idx, f, last}] = ans;
}

int main(void) {
    ll a, b;
    cin >> a >> b;
    string sa = to_string(a - 1), sb = to_string(b);
    ll ab = solve(sb, 0, true, -1);
    dp.clear();
    ll aa = (a == 0) ? 0 : solve(sa, 0, true, -1);
    cout << (ab - aa) << "\n";
}