#include <bits/stdc++.h>
using namespace std;

#define vec vector
typedef long long ll;
typedef vec<int> vi;

int main(void) {
    string s;
    cin >> s;
    int cnt[26];
    memset(&cnt[0], 0, sizeof(cnt));
    for (char c : s)
        cnt[c - 'A']++;
    char sing = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 != 0) {
            // cout << i << "\n";
            if (sing) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            sing = ((char)i + 'A');
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            cout << char((char)i + 'A');
        }
    }
    if (sing != 0) cout << sing;
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            cout << char((char)i + 'A');
        }
    }
    cout << "\n";
    return 0;
}
