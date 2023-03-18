#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> as(n), bs(n);
    for (int i = 0; i < n; i++)
        cin >> as[i] >> bs[i];
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    int ap = 0, bp = 0, cur = 0, ans = 0;
    while (ap != as.size()) {
        while (bs[bp] < as[ap]) {
            bp++;
            cur--;
        }
        ap++;
        cur++;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}