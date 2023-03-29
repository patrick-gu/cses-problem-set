#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<set<int>> es(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        es[a].insert(b), es[b].insert(a);
    }
    vector<int> best(n, INT_MAX), last(n);
    best[0] = 0;
    last[0] = -1;
    deque<int> q;
    q.push_back(0);
    while (q.size()) {
        int v = q.front();
        q.pop_front();
        for (int e : es[v]) {
            if (best[v] + 1 < best[e]) {
                best[e] = best[v] + 1;
                last[e] = v;
                q.push_back(e);
            }
        }
    }
    if (best.back() == INT_MAX) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    deque<int> ans;
    int cur = n - 1;
    while (cur != -1) {
        ans.push_front(cur);
        cur = last[cur];
    }
    cout << ans.size() << "\n";
    cout << ans[0] + 1;
    for (int i = 1; i < ans.size(); i++)
        cout << " " << (ans[i] + 1);
    cout << "\n";
}