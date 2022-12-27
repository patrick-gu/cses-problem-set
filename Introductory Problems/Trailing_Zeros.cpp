#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ll n;
    cin >> n;
    ll a = 1;
    ll s = 0;
    while (n >= a) {
        a *= 5;
        s += n / a;
    }
    cout << s << "\n";
}
