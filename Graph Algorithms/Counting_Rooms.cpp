#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> d, r, sz;
    int cnt;
    UnionFind(int n) : d(n), r(n), sz(n, 1), cnt(n) {
        iota(d.begin(), d.end(), 0);
    }
    int find(int n) {
        return d[n] == n ? n : d[n] = find(d[n]);
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (r[a] > r[b]) swap(a, b);
        if (r[a] == r[b]) r[b]++;
        d[a] = b;
        sz[b]++;
        cnt--;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (int i = 0; i < n; i++)
        cin >> mp[i];
    UnionFind uf(n * m);
    int wall = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '#') {
                wall++;
            } else {
                if (i != 0 && mp[i - 1][j] == '.')
                    uf.join(i * m + j, (i - 1) * m + j);
                if (i != n - 1 && mp[i + 1][j] == '.')
                    uf.join(i * m + j, (i + 1) * m + j);
                if (j != 0 && mp[i][j - 1] == '.')
                    uf.join(i * m + j, (i)*m + j - 1);
                if (j != m - 1 && mp[i][j + 1] == '.')
                    uf.join(i * m + j, (i)*m + j + 1);
            }
        }
    }
    cout << uf.cnt - wall << "\n";
}