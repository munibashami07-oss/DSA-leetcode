#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, a1, b1, a2, b2;
        cin >> a >> b >> a1 >> b1 >> a2 >> b2;

        // Chef needs a language whose feature SET (order doesn't matter)
        // equals {A, B}. Compare unordered pairs by sorting them.
        int need[2] = {a, b};
        int opt1[2] = {a1, b1};
        int opt2[2] = {a2, b2};
        sort(need, need + 2);
        sort(opt1, opt1 + 2);
        sort(opt2, opt2 + 2);

        if (need[0] == opt1[0] && need[1] == opt1[1]) {
            cout << 1 << "\n";
        } else if (need[0] == opt2[0] && need[1] == opt2[1]) {
            cout << 2 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}