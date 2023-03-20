#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
    int n;
    cin >> n;
    vector<ll> ts(n);
    for (int i = 0; i < n; i++)
        cin >> ts[i];
    sort(ts.begin(), ts.end());
    ll tb = accumulate(ts.begin(), prev(ts.end()), 0LL);
    if (ts.back() > tb) {
        cout << ts.back() * 2 << "\n";
    } else {
        // If we have one in non-increasing order, and another
        // with the greatest element moved to the back, then
        // we cannot have any overlap in books
        cout << tb + ts.back() << "\n";
    }
}