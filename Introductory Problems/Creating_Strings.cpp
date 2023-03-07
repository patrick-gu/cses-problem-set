#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> idxs(n);
    iota(idxs.begin(), idxs.end(), 0);
    set<string> ans;
    do {
        string c;
        for (int i : idxs) {
            c.push_back(s[i]);
        }
        ans.insert(c);
    } while (next_permutation(idxs.begin(), idxs.end()));
    cout << ans.size() << "\n";
    for (auto& s1 : ans)
        cout << s1 << "\n";
}