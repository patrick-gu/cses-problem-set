#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    vector<pair<int, int>> lst(n);
    for (int i = 0; i < n; i++) {
        lst[i] = {i - 1, i + 1};
    }
    lst[0] = {n - 1, 1};
    lst[n - 1] = {n - 2, 0};
    int i = 1;

    for (;;) {
        auto [last, next] = lst[i];
        if (i == next) {
            cout << (i + 1) << "\n";
            break;
        }
        lst[last].second = next;
        lst[next].first = last;
        cout << (i + 1) << " ";
        i = lst[next].second;
    }
}