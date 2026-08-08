#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        // Chef must use exactly two of the three spells. To maximize the
        // total hit points, pick the two largest powers among A, B, C.
        // Equivalently: sum of all three minus the smallest one.
        long long smallest = min({a, b, c});
        long long total = a + b + c;

        cout << (total - smallest) << "\n";
    }
    return 0;
}