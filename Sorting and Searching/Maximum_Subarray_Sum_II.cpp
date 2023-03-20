#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class MinST {
    size_t sz;
    vector<ll> data;

    ll conquer(ll a, ll b) {
        return min(a, b);
    }

    ll query(size_t a, size_t b, size_t p, size_t l, size_t r) {
        if (b < l || r < a) return LONG_LONG_MAX;
        if (a <= l && r <= b) return data[p];
        size_t m = l + (r - l) / 2;
        return conquer(query(a, b, p * 2, l, m),
                       query(a, b, p * 2 + 1, m + 1, r));
    }

   public:
    MinST(size_t n) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        data = vector<ll>(sz * 2);
    }

    void update(size_t at, size_t value) {
        at += sz;
        data[at] = value;
        at /= 2;
        for (; at > 0; at /= 2)
            data[at] = conquer(data[at * 2], data[at * 2 + 1]);
    }

    ll query(size_t a, size_t b) {
        return query(a, b, 1, 0, sz - 1);
    }
};

int main(void) {
    ll n, a, b;
    cin >> n >> a >> b;
    ll xs[n];
    for (ll i = 0; i < n; i++)
        cin >> xs[i];
    ll cur = 0;
    MinST st(n + 1);
    ll ans = LONG_LONG_MIN;
    for (ll i = 0; i < n; i++) {
        cur += xs[i];
        if (i >= a - 1)
            ans = max(ans,
                      cur - st.query(max(0LL, i - b + 1), max(0LL, i - a + 1)));
        st.update(i + 1, cur);
    }
    cout << ans << "\n";
}