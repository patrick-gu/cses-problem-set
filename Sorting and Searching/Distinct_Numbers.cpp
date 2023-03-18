#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    unordered_set<int> s;
    while (n--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
}