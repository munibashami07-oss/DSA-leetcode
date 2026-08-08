#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // Easy:   1 <= x < 100
        // Medium: 100 <= x < 200
        // Hard:   200 <= x <= 300
        if (x < 100) {
            cout << "Easy\n";
        } else if (x < 200) {
            cout << "Medium\n";
        } else {
            cout << "Hard\n";
        }
    }
    return 0;
}