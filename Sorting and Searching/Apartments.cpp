#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> as(n);
    for (int i = 0; i < n; i++)
        cin >> as[i];
    vector<int> bs(m);
    for (int i = 0; i < n; i++)
        cin >> bs[i];
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    int ap = 0;
    int ans = 0;
    for (int b : bs) {
        if (as[ap] - k > b) continue;
        while (ap < n && as[ap] + k < b)
            ap++;
        if (ap < n) {
            if (as[ap] - k > b) {
                continue;
            } else {
                ap++;
                ans++;
            }
        } else {
            break;
        }
    }
    cout << ans << endl;
}