#include <bits/stdc++.h>
using namespace std;

#define vec vector
typedef long long ll;
typedef vec<int> vi;

bool solve(int a, int b) {
    if ((a + b) % 3 != 0) return false;
    if (a > b * 2 || b > a * 2) return false;
    return true;
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (solve(a, b) ? "YES\n" : "NO\n");
    }
    return 0;
}
