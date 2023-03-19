#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> is(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x, x--, is[x] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (is[i] < is[i - 1]) ans++;
    cout << ans << endl;
}