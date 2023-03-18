#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> ms(n);
    for (int i = 0; i < n; i++)
        cin >> ms[i].first >> ms[i].second;
    sort(ms.begin(), ms.end(), [](auto& a, auto& b) {
        if (a.second < b.second) {
            return true;
        }
        if (a.second > b.second) {
            return false;
        }
        return a.first < b.first;
    });
    int time = 0;
    int mp = 0, ans = 0;
    for (;;) {
        if (mp == ms.size()) break;
        if (ms[mp].first < time) {
            mp++;
            continue;
        }
        time = ms[mp].second;
        ans++;
    }
    cout << ans << endl;
}