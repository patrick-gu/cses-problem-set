#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (int i = 0; i < n; i++)
        cin >> mp[i];
    vector<vector<int>> shortest(n, vector<int>(m, INT_MAX));
    vector<vector<char>> dir(n, vector<char>(m));
    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'A') {
                q.push_back({i, j});
                shortest[i][j] = 0;
            }
        }
    }
    while (q.size()) {
        auto [y, x] = q.front();
        q.pop_front();
        int s = shortest[y][x] + 1;
        if (y != 0 && s < shortest[y - 1][x] && mp[y - 1][x] != '#')
            shortest[y - 1][x] = s, dir[y - 1][x] = 'U',
                         q.push_back({y - 1, x});
        if (y != n - 1 && s < shortest[y + 1][x] && mp[y + 1][x] != '#')
            shortest[y + 1][x] = s, dir[y + 1][x] = 'D',
                         q.push_back({y + 1, x});
        if (x != 0 && s < shortest[y][x - 1] && mp[y][x - 1] != '#')
            shortest[y][x - 1] = s, dir[y][x - 1] = 'L',
                            q.push_back({y, x - 1});
        if (x != m - 1 && s < shortest[y][x + 1] && mp[y][x + 1] != '#')
            shortest[y][x + 1] = s, dir[y][x + 1] = 'R',
                            q.push_back({y, x + 1});
    }

    int ey = -1, ex = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'B') {
                ey = i;
                ex = j;
                if (shortest[i][j] == INT_MAX) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    deque<char> ans;
    while (dir[ey][ex]) {
        ans.push_front(dir[ey][ex]);
        switch (dir[ey][ex]) {
            case 'D':
                ey--;
                break;
            case 'U':
                ey++;
                break;
            case 'L':
                ex++;
                break;
            case 'R':
                ex--;
                break;
        }
    }
    cout << ans.size() << "\n";
    for (char c : ans)
        putchar(c);
    cout << "\n";
}