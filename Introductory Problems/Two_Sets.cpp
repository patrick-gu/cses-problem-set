#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ll n;
    cin >> n;
    if (n % 4 == 0) {
        cout << "YES\n";
        vector<int> a1;
        vector<int> a2;
        for (int i = 1; i <= n; i += 4) {
            a1.push_back(i);
            a1.push_back(i + 3);
            a2.push_back(i + 1);
            a2.push_back(i + 2);
        }
        cout << a1.size() << "\n";
        for (int i = 0; i < a1.size() - 1; i++) {
            cout << a1[i] << " ";
        }
        cout << a1.back() << "\n";
        cout << a2.size() << "\n";
        for (int i = 0; i < a2.size() - 1; i++) {
            cout << a2[i] << " ";
        }
        cout << a2.back() << "\n";
    } else if (n % 4 == 3) {
        cout << "YES\n";
        vector<int> a1 = {1, 2};
        vector<int> a2 = {3};
        for (int i = 4; i <= n; i += 4) {
            a1.push_back(i);
            a1.push_back(i + 3);
            a2.push_back(i + 1);
            a2.push_back(i + 2);
        }
        cout << a1.size() << "\n";
        for (int i = 0; i < a1.size() - 1; i++) {
            cout << a1[i] << " ";
        }
        cout << a1.back() << "\n";
        cout << a2.size() << "\n";
        for (int i = 0; i < a2.size() - 1; i++) {
            cout << a2[i] << " ";
        }
        cout << a2.back() << "\n";
    } else {
        cout << "NO\n";
    }
}
