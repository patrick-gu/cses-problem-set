#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> xs;
    while (n--) {
        int x;
        cin >> x;
        xs.push_back(x);
    }
    sort(xs.begin(), xs.end());
    cout << unique(xs.begin(), xs.end()) - xs.begin() << "\n";
}