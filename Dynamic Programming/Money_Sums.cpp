#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    vector<bool> pos(100001);
    pos[0] = 1;
    for (int x : xs)
        for (int j = 100000; j >= 0; j--)
            if (pos[j]) pos[j + x] = true;
    vector<int> ans;
    for (int i = 1; i <= 100000; i++)
        if (pos[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << " " << ans[i];
    cout << "\n";
}