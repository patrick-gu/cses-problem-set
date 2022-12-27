#include <bits/stdc++.h>
using namespace std;

#define vec vector
typedef long long ll;
typedef vec<int> vi;

int main(void) {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    if (n == 4) {
        cout << "2 4 1 3\n";
        return 0;
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    if (n % 2 == 0) {
        for (int i = 2; i <= n - 2; i += 2) {
            cout << i << " ";
        }
        cout << n << "\n";
    } else {
        for (int i = 2; i <= n - 3; i += 2) {
            cout << i << " ";
        }
        cout << (n - 1) << "\n";
    }
    return 0;
}
