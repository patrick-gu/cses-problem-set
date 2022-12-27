#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<bool> p(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        p[a] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!p[i]) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
