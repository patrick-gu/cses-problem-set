#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<string> ss(8);
    for (int i = 0; i < 8; i++)
        cin >> ss[i];
    vector<int> pos(8);
    iota(pos.begin(), pos.end(), 0);
    int acc = 0;
    do {
        vector<bool> diag1(15), diag2(15);
        for (int y = 0; y < 8; y++) {
            int x = pos[y];
            if (ss[y][x] == '*') goto fail;
            if (diag1[x - y + 7]) {
                goto fail;
            }
            diag1[x - y + 7] = true;
            if (diag2[(7 - x) - y + 7]) {
                goto fail;
            }
            diag2[(7 - x) - y + 7] = true;
        }
        acc++;
    fail:;
    } while (next_permutation(pos.begin(), pos.end()));
    cout << acc << endl;
}