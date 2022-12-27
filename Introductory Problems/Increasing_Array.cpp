#include <bits/stdc++.h>
using namespace std;

#define vec vector
typedef long long ll;
typedef vec<int> vi;

int main(void) {
    ll n;
    cin >> n;
    ll total = 0;
    ll last;
    cin >> last;
    for (ll i = 1; i < n; i++) {
        ll x;
        cin >> x;
        if (x < last) {
            total += last - x;
        } else {
            last = x;
        }
    }
    cout << total << "\n";
    return 0;
}
