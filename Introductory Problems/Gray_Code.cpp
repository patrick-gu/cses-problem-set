#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    auto a = solve(n - 1);
    int k = a.size();
    for (int i = k - 1; i >= 0; i--) {
        a.push_back(a[i]);
        a.back().push_back('1');
        a[i].push_back('0');
    }
    return a;
}

int main(void) {
    int n;
    cin >> n;
    for (auto& s : solve(n))
        cout << s << "\n";
}