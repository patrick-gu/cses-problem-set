#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct LowerHigher {
    multiset<ll> l, h;
    ll lower = 0, higher = 0, mid = -1;
    void add(ll n) {
        if (mid == -1) {
            if (l.empty()) {
                mid = n;
            } else if (n >= *l.rbegin()) {
                if (n <= *h.begin()) {
                    mid = n;
                } else {
                    h.insert(n);
                    mid = *h.begin();
                    h.erase(h.begin());
                    higher += n - mid;
                }
            } else {
                l.insert(n);
                mid = *l.rbegin();
                l.erase(prev(l.end()));
                lower += n - mid;
            }
        } else {
            if (n >= mid) {
                l.insert(mid);
                lower += mid;
                h.insert(n);
                higher += n;
            } else {
                l.insert(n);
                lower += n;
                h.insert(mid);
                higher += mid;
            }
            mid = -1;
        }
    }
    void remove(ll n) {
        if (mid == -1) {
            if (n <= *l.rbegin()) {
                l.erase(l.find(n));
                lower -= n;
                mid = *h.begin();
                higher -= *h.begin();
                h.erase(h.begin());
            } else {
                h.erase(h.find(n));
                higher -= n;
                mid = *l.rbegin();
                lower -= *l.rbegin();
                l.erase(prev(l.end()));
            }
        } else {
            if (n == mid) {
                mid = -1;
            } else if (n < mid) {
                l.erase(l.find(n));
                lower -= n;
                l.insert(mid);
                lower += mid;
                mid = -1;
            } else {
                h.erase(h.find(n));
                higher -= n;
                h.insert(mid);
                higher += mid;
                mid = -1;
            }
        }
    }
};

int main(void) {
    int n, k;
    cin >> n >> k;
    int xs[n];
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    // https://www.quora.com/Why-does-the-median-minimize-the-sum-of-absolute-deviations/answer/Michal-Fori%C5%A1ek
    LowerHigher lh;
    for (int i = 0; i < k; i++)
        lh.add(xs[i]);
    cout << lh.higher - lh.lower;
    for (int i = 1; i + k - 1 < n; i++) {
        lh.remove(xs[i - 1]);
        lh.add(xs[i + k - 1]);
        cout << " " << (lh.higher - lh.lower);
    }
    cout << "\n";
}