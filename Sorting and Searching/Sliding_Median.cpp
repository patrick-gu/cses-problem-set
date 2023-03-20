#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set =
    __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

int main(void) {
    int n, k;
    cin >> n >> k;
    int xs[n];
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    ordered_set ns;
    for (int i = 0; i < k; i++)
        ns.insert(xs[i]);

    int med = (k % 2) ? *ns.find_by_order(ns.size() / 2)
                      : min(*ns.find_by_order(ns.size() / 2),
                            *ns.find_by_order(ns.size() / 2 - 1));
    cout << med;
    ns.erase(prev(ns.lower_bound(xs[0])));
    for (int i = 1; i + k - 1 < n; i++) {
        ns.insert(xs[i + k - 1]);
        med = (k % 2) ? *ns.find_by_order(ns.size() / 2)
                      : min(*ns.find_by_order(ns.size() / 2),
                            *ns.find_by_order(ns.size() / 2 - 1));
        cout << " " << med;
        ns.erase(prev(ns.lower_bound(xs[i])));
    }
    cout << "\n";
}