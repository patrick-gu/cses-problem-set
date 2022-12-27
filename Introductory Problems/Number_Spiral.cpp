#include <bits/stdc++.h>
using namespace std;

#define vec vector
typedef long long ll;
typedef vec<int> vi;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;

        ll m = max(x, y);
        ll n = m * m - m + 1;
        if (m % 2 == 0) {
            n += y - x;
        } else {
            n += x - y;
        }
        cout << n << "\n";
    }
    return 0;
}
