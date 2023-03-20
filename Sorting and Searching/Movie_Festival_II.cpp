#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
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
    multiset<int> times;
    for (int i = 0; i < k; i++)
        times.insert(0);
    int ans = 0;
    for (auto [start, end] : ms) {
        auto it = times.upper_bound(start);
        if (it == times.begin()) continue;
        times.erase(prev(it));
        times.insert(end);
        ans++;
    }
    cout << ans << endl;
}