#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int n;
    cin >> n;
    vector<tuple<int, int, ll>> ps(n);
    for (int i = 0; i < n; i++)
        cin >> get<0>(ps[i]) >> get<1>(ps[i]) >> get<2>(ps[i]);

    multiset<tuple<int, bool, int, ll>> events;
    for (auto [a, b, p] : ps) {
        events.insert({a, 1, b, p});
    }
    ll best = 0;
    while (events.size()) {
        auto [t, k, b, p] = *events.begin();
        events.erase(events.begin());
        if (k) {
            events.insert({b + 1, 0, 0, best + p});
        } else {
            best = max(best, p);
        }
    }
    cout << best << "\n";
}