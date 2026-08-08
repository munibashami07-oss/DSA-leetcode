#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Repeatedly subtracting K from N (as long as the result stays
        // non-negative) drives N down to N mod K — the remainder after
        // removing as many full copies of K as possible.
        //
        // Special case: if K == 0, subtracting K never changes N, so the
        // smallest reachable value is N itself.
        if (k == 0) {
            cout << n << "\n";
        } else {
            cout << (n % k) << "\n";
        }
    }
    return 0;
}