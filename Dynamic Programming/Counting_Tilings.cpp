#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void transition(vector<bool>& trs, int n, int st, int nst, int idx) {
    if (idx == n) {
        trs[nst] = true;
        return;
    }
    if ((st >> idx) & 1) {
        transition(trs, n, st, nst, idx + 1);
        return;
    }
    if (idx + 1 < n && !((st >> (idx + 1)) & 1)) {
        transition(trs, n, st, nst, idx + 2);
    }
    transition(trs, n, st, nst | (1 << idx), idx + 1);
}

vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> out(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            ll v = 0;
            for (int k = 0; k < a[0].size(); k++) {
                // avoid using modulus as much as possible
                v += (ll(a[i][k]) * ll(b[k][j])) % MOD;
            }
            v %= MOD;
            out[i][j] = v;
        }
    }
    return out;
}

vector<vector<int>> pow(vector<vector<int>>& m, int e) {
    if (e == 1) return m;
    auto ms = pow(m, e / 2);
    auto ml = mul(ms, ms);
    if (e % 2)
        return mul(ml, m);
    else
        return ml;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> trs(1 << n, vector<bool>(1 << n));
    for (int i = 0; i < (1 << n); i++) {
        transition(trs[i], n, i, 0, 0);
    }
    // compress matrix to eliminate states which are unreachable
    vector<bool> reachable(1 << n);
    reachable[0] = true;
    deque<int> q;
    q.push_back(0);
    while (q.size()) {
        int c = q.back();
        q.pop_back();
        for (int i = 0; i < (1 << n); i++) {
            if (trs[c][i] && !reachable[i]) {
                reachable[i] = true;
                q.push_back(i);
            }
        }
    }
    vector<int> rs;
    for (int i = 0; i < reachable.size(); i++) {
        if (reachable[i]) {
            rs.push_back(i);
        }
    }
    // using int matrix can be faster than long long
    vector<vector<int>> ms(rs.size(), vector<int>(rs.size()));
    for (int i = 0; i < rs.size(); i++) {
        for (int j = 0; j < rs.size(); j++) {
            ms[i][j] = trs[rs[i]][rs[j]];
        }
    }
    auto m1 = pow(ms, m);
    cout << m1[0][0] << "\n";
}