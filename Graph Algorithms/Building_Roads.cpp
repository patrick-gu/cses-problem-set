#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> d, r, sz;
    UnionFind(int n) : d(n), r(n), sz(n, 1) {
        iota(d.begin(), d.end(), 0);
    }
    int find(int n) {
        return (d[n] == n) ? n : (d[n] = find(d[n]));
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (r[a] > r[b]) swap(a, b);
        if (r[a] == r[b]) r[b]++;
        d[a] = d[b];
        sz[b] += sz[a];
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        uf.join(a, b);
    }
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(uf.find(i));
    cout << s.size() - 1 << "\n";
    int last = -1;
    for (int v : s) {
        if (last != -1) {
            cout << last + 1 << " " << v + 1 << "\n";
        }
        last = v;
    }
}