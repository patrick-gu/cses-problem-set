#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

using ll = long long;

int main(void) {
    ll n, k;
    cin >> n >> k;
    ordered_set s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    ll i = 0;
    while (s.size()) {
        i += k;
        i %= s.size();
        auto it = s.find_by_order(i);
        int v = *it;
        s.erase(it);
        if (s.empty()) {
            cout << v << "\n";
        } else {
            cout << v << " ";
        }
    }
}