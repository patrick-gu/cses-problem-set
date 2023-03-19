#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> ks(n);
    for (int i = 0; i < n; i++)
        cin >> ks[i];
    multiset<int> towers;
    for (int k : ks) {
        auto it = towers.upper_bound(k);
        if (it == towers.end()) {
            towers.insert(k);
        } else {
            towers.erase(it);
            towers.insert(k);
        }
    }
    cout << towers.size() << "\n";
}