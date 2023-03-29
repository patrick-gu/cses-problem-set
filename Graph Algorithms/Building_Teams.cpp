#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<set<int>> es(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        es[a].insert(b), es[b].insert(a);
    }
    vector<int> col(n, -1);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (col[i] != -1) continue;
        q.push_back(i);
        col[i] = 0;
        while (q.size()) {
            int f = q.front();
            q.pop_front();
            int a = 1 - col[f];
            for (int e : es[f]) {
                if (col[e] == -1) {
                    col[e] = a;
                    q.push_back(e);
                } else if (col[e] != a) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }
    cout << col[0] + 1;
    for (int i = 1; i < col.size(); i++)
        cout << " " << col[i] + 1;
    cout << "\n";
}