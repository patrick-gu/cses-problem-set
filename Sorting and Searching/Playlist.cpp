#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> ks(n);
    for (int i = 0; i < n; i++)
        cin >> ks[i];
    set<int> cur;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && cur.find(ks[j]) == cur.end()) {
            cur.insert(ks[j]);
            j++;
        }
        ans = max(ans, j - i);
        cur.erase(cur.find(ks[i]));
    }
    cout << ans << "\n";
}