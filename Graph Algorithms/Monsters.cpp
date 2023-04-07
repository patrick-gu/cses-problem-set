#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for (int i = 0; i < n; i++)
        cin >> map[i];
    vector<vector<int>> dpm(n, vector<int>(m, INT_MAX)),
        dpa(n, vector<int>(m, INT_MAX));
    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 'M') dpm[i][j] = 0, q.push_back({i, j});
    while (q.size()) {
        auto [y, x] = q.front();
        q.pop_front();
        if (y != 0 && map[y - 1][x] != '#' && dpm[y][x] + 1 < dpm[y - 1][x])
            dpm[y - 1][x] = dpm[y][x] + 1, q.push_back({y - 1, x});
        if (y != n - 1 && map[y + 1][x] != '#' && dpm[y][x] + 1 < dpm[y + 1][x])
            dpm[y + 1][x] = dpm[y][x] + 1, q.push_back({y + 1, x});
        if (x != 0 && map[y][x - 1] != '#' && dpm[y][x] + 1 < dpm[y][x - 1])
            dpm[y][x - 1] = dpm[y][x] + 1, q.push_back({y, x - 1});
        if (x != m - 1 && map[y][x + 1] != '#' && dpm[y][x] + 1 < dpm[y][x + 1])
            dpm[y][x + 1] = dpm[y][x] + 1, q.push_back({y, x + 1});
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 'A') dpa[i][j] = 0, q.push_back({i, j});
    vector<string> dpc(n, string(m, '0'));
    while (q.size()) {
        auto [y, x] = q.front();
        q.pop_front();
#define TRY(_y, _x, _c)                                      \
    if (map[_y][_x] != '#' && dpa[y][x] + 1 < dpm[_y][_x] && \
        dpa[y][x] + 1 < dpa[_y][_x])                         \
        dpa[_y][_x] = dpa[y][x] + 1, q.push_back({_y, _x}), dpc[_y][_x] = _c;
        if (y != 0) TRY(y - 1, x, 'U');
        if (y != n - 1) TRY(y + 1, x, 'D');
        if (x != 0) TRY(y, x - 1, 'L');
        if (x != m - 1) TRY(y, x + 1, 'R');
    }
    int ay = -1, ax = -1;
    for (int i = 0; i < n; i++)
        if (dpa[i][0] != INT_MAX) ay = i, ax = 0;
    for (int i = 0; i < n; i++)
        if (dpa[i][m - 1] != INT_MAX) ay = i, ax = m - 1;
    for (int i = 0; i < m; i++) {
        if (dpa[0][i] != INT_MAX) ay = 0, ax = i;
        if (dpa[n - 1][i] != INT_MAX) ay = n - 1, ax = i;
    }
    if (ay == -1) {
        cout << "NO\n";
        return 0;
    }
    string ans;
    while (map[ay][ax] != 'A') {
        ans.push_back(dpc[ay][ax]);
        switch (dpc[ay][ax]) {
            case 'U':
                ay++;
                break;
            case 'D':
                ay--;
                break;
            case 'R':
                ax--;
                break;
            case 'L':
                ax++;
                break;
        }
    }
    cout << "YES\n" << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
        putchar(ans[i]);
    cout << "\n";
}