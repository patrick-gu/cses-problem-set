#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> es(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> es[i];
    vector<pair<int, int>> qs(q);
    for (int i = 0; i < q; i++)
        cin >> qs[i].first >> qs[i].second;
    vector<vector<int>> bs(n + 1, vector<int>(20));
    bs[1][0] = -1;
    for (int i = 2; i <= n; i++) {
        bs[i][0] = es[i];
    }
    for (int p = 1; p < 20; p++) {
        for (int i = 1; i <= n; i++) {
            int b = bs[i][p - 1];
            bs[i][p] = (b == -1) ? -1 : bs[b][p - 1];
        }
    }
    vector<vector<int>> cs(n + 1);
    for (int i = 2; i <= n; i++) {
        cs[es[i]].push_back(i);
    }
    vector<int> trav;
    vector<int> first(n + 1), last(n + 1);
    function<void(int)> mtrav = [&trav, &cs, &first, &last, &mtrav](int cur) {
        first[cur] = trav.size();
        trav.push_back(cur);
        for (int c : cs[cur])
            mtrav(c);
        last[cur] = trav.size();
        trav.push_back(cur);
    };
    mtrav(1);

    for (auto [a, b] : qs) {
#define ISBOSS(_c) \
    ((_c) == -1 || (first[_c] <= first[b] && first[b] <= last[_c]))

        if (ISBOSS(a)) {
            cout << a << "\n";
            continue;
        }

        for (int l = 19; l >= 0; l--) {
            int c = bs[a][l];
            if (!ISBOSS(c)) {
                a = c;
            }
        }

        cout << bs[a][0] << "\n";
    }
}