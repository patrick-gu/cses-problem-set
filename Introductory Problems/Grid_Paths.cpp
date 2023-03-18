#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

// vector<vector<bool>> vis(7, vector<bool>(7));
bool vis[7][7];
string cur;
vector<string> ans;
void solve(int y, int x) {
    if (y == 6 && x == 0) {
        if (cur.size() == 48) {
            ans.push_back(cur);
        }
        return;
    }
    if (cur.size() == 48) return;
    // Optimization from Competitive Programmer's Handbook
    if (((y == 6 || vis[y + 1][x]) && (y == 0 || vis[y - 1][x])) &&
        ((x != 0 && !vis[y][x - 1]) && ((x != 6) && !vis[y][x + 1]))) {
        return;
    }
    if (((x == 6 || vis[y][x + 1]) && (x == 0 || vis[y][x - 1])) &&
        ((y != 0 && !vis[y - 1][x]) && ((y != 6) && !vis[y + 1][x]))) {
        return;
    }
    if (x != 6 && !vis[y][x + 1]) {
        vis[y][x + 1] = true;
        cur.push_back('R');
        solve(y, x + 1);
        cur.pop_back();
        vis[y][x + 1] = false;
    }
    if (y != 6 && !vis[y + 1][x]) {
        vis[y + 1][x] = true;
        cur.push_back('D');
        solve(y + 1, x);
        cur.pop_back();
        vis[y + 1][x] = false;
    }
    if (y != 0 && !vis[y - 1][x]) {
        vis[y - 1][x] = true;
        cur.push_back('U');
        solve(y - 1, x);
        cur.pop_back();
        vis[y - 1][x] = false;
    }
    if (x != 0 && !vis[y][x - 1]) {
        vis[y][x - 1] = true;
        cur.push_back('L');
        solve(y, x - 1);
        cur.pop_back();
        vis[y][x - 1] = false;
    }
}

int main(void) {
    vis[0][0] = true;
    solve(0, 0);
    string s;
    cin >> s;
    int acc = 0;
    for (string a : ans) {
        for (int i = 0; i < 48; i++) {
            if (!(s[i] == '?' || s[i] == a[i])) goto fail;
        }
        acc++;
    fail:;
    }
    cout << acc << "\n";
}