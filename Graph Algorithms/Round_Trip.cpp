#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>>& es, vector<bool>& vis, vector<bool>& curvis,
           deque<int>& q, int i) {
    vis[i] = 1;
    if (curvis[i]) {
        if (!(q.size() < 2 || q[q.size() - 2] != i)) return 0;
        vector<int> ans;
        ans.push_back(i);
        while (q.back() != i) {
            ans.push_back(q.back());
            q.pop_back();
        }
        ans.push_back(i);
        cout << ans.size() << "\n";
        cout << ans[0] + 1;
        for (int j = 1; j < ans.size(); j++) {
            cout << " " << ans[j] + 1;
        }
        cout << "\n";
        return 1;
    }
    q.push_back(i);
    curvis[i] = 1;
    for (int e : es[i]) {
        if (solve(es, vis, curvis, q, e)) return 1;
    }
    q.pop_back();
    curvis[i] = 0;
    return 0;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> es(n);
    for (int i = 0; i++ < m;) {
        int a, b;
        cin >> a >> b, a--, b--;
        es[a].push_back(b), es[b].push_back(a);
    }
    vector<bool> vis(n), curvis(n);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (solve(es, vis, curvis, q, i)) return 0;
    }
    cout << "IMPOSSIBLE\n";
}