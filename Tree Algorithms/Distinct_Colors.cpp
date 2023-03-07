#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void merge(unordered_set<int>& a, unordered_set<int>& b) {
    if (a.size() < b.size()) swap(a, b);
    for (int l : b)
        a.insert(l);
}
 
unordered_set<int> solve(vector<int>& ans, vector<int>& cs,
                         vector<unordered_set<int>>& es, int k) {
    unordered_set<int> r;
    r.insert(cs[k]);
    for (int next : es[k]) {
        es[next].erase(es[next].find(k));
        unordered_set<int> a = solve(ans, cs, es, next);
        merge(r, a);
    }
    ans[k] = r.size();
    return r;
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> cs(n);
    for (int i = 0; i < n; i++) {
        cin >> cs[i];
    }
    vector<unordered_set<int>> es(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        es[a].insert(b);
        es[b].insert(a);
    }
    vector<int> ans(n);
    solve(ans, cs, es, 0);
    for (int i = 0; i + 1 < n; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << "\n";
}