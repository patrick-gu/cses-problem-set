#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> cs(n);
    for (int i = 0; i < n; i++)
        cin >> cs[i].first >> cs[i].second;
    vector<int> vs;
    for (auto [a, b] : cs)
        vs.push_back(a), vs.push_back(b);
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    for (auto& [a, b] : cs)
        a = lower_bound(vs.begin(), vs.end(), a) - vs.begin(),
        b = lower_bound(vs.begin(), vs.end(), b) - vs.begin();
    vector<int> diff(vs.size() + 1);
    for (auto [a, b] : cs)
        diff[a]++, diff[b + 1]--;
    int cur = 0, best = 0;
    for (int d : diff) {
        cur += d;
        best = max(best, cur);
    }
    cout << best << "\n";
    vector<int> ans(n);
    vector<int> free(best);
    iota(free.begin(), free.end(), 1);
    vector<tuple<int, bool, int>> insns;
    for (int i = 0; i < cs.size(); i++)
        insns.push_back({cs[i].first, 1, i}),
            insns.push_back({cs[i].second + 1, 0, i});
    sort(insns.begin(), insns.end());
    for (auto [t, c, i] : insns) {
        if (c) {
            ans[i] = free.back();
            free.pop_back();
        } else {
            free.push_back(ans[i]);
        }
    }
    cout << ans[0];
    for (int i = 1; i < n; i++)
        cout << " " << ans[i];
    cout << "\n";
}