#include <bits/stdc++.h>
using namespace std;

int other(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 2) return 1;
    if (b == 3) return 2;
    return 3;
}

void move(int a, int b, int k) {
    // cout << "m " << a << " " << b << " " << k << "\n";
    if (k == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    int o = other(a, b);
    move(a, o, k - 1);
    cout << a << " " << b << "\n";
    move(o, b, k - 1);
}

int main(void) {
    int n;
    cin >> n;
    cout << ((1 << n) - 1) << "\n";
    move(1, 3, n);
}