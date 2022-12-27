#include <bits/stdc++.h>
using namespace std;

#define vec vector
typedef long long ll;
typedef vec<int> vi;

int main(void) {
    string s;
    cin >> s;
    char last = s[0];
    int count = 1;
    int best = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == last) {
            count++;
        } else {
            best = max(best, count);
            last = s[i];
            count = 1;
        }
    }
    best = max(best, count);
    cout << best << "\n";
    return 0;
}
