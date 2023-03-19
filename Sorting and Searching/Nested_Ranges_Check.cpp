#include <bits/stdc++.h>
using namespace std;

class Seg {
    int n;
    vector<int> data;
    int query(int p, int l, int r, int a, int b) {
        if (r < a || l > b) return 0;
        if (a <= l && r <= b) return data[p];
        int m = (l + r) / 2;
        return query(p * 2, l, m, a, b) + query(p * 2 + 1, m + 1, r, a, b);
    }

   public:
    Seg(int sz) {
        n = 1;
        while (n < sz)
            n *= 2;
        data = vector<int>(n * 2);
    }

    void update(int p, int v) {
        int c = n + p;
        while (c > 0) {
            data[c] += v;
            c /= 2;
        }
    }

    int query(int a, int b) {
        return query(1, 0, n - 1, a, b);
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> rs(n);
    for (int i = 0; i < n; i++)
        cin >> rs[i].first >> rs[i].second;
    vector<int> vs;
    for (int i = 0; i < n; i++)
        vs.push_back(rs[i].first), vs.push_back(rs[i].second);
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    for (int i = 0; i < n; i++)
        rs[i].first =
            lower_bound(vs.begin(), vs.end(), rs[i].first) - vs.begin(),
        rs[i].second =
            lower_bound(vs.begin(), vs.end(), rs[i].second) - vs.begin();
    vector<int> out(n), in(n);
    Seg seg(vs.size());
    vector<tuple<int, int, int>> rs1;
    for (int i = 0; i < n; i++)
        rs1.push_back({rs[i].first, rs[i].second, i});
    sort(rs1.begin(), rs1.end(), [](auto& a, auto& b) {
        if (get<1>(a) < get<1>(b)) return true;
        if (get<1>(a) > get<1>(b)) return false;
        return get<0>(a) > get<0>(b);
    });
    for (int i = 0; i < rs1.size(); i++) {
        out[get<2>(rs1[i])] = seg.query(get<0>(rs1[i]), vs.size());
        seg.update(get<0>(rs1[i]), 1);
    }
    seg = Seg(vs.size());
    for (int i = rs1.size() - 1; i >= 0; i--) {
        in[get<2>(rs1[i])] = seg.query(0, get<0>(rs1[i]));
        seg.update(get<0>(rs1[i]), 1);
    }

    cout << (out[0] != 0);
    for (int i = 1; i < out.size(); i++)
        cout << " " << (out[i] != 0);
    cout << "\n";
    cout << (in[0] != 0);
    for (int i = 1; i < in.size(); i++)
        cout << " " << (in[i] != 0);
    cout << "\n";
}