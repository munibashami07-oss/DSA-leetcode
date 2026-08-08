#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        long long best = -1; // ratings are >= 1, so -1 means "none found yet"
        for (int i = 0; i < n; i++) {
            long long s, r;
            cin >> s >> r;
            // Only consider movies that fit in the remaining space.
            if (s <= x) {
                best = max(best, r);
            }
        }

        // Problem guarantees at least one movie fits, so best is always set.
        cout << best << "\n";
    }
    return 0;
}#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        long long best = -1; // ratings are >= 1, so -1 means "none found yet"
        for (int i = 0; i < n; i++) {
            long long s, r;
            cin >> s >> r;
            // Only consider movies that fit in the remaining space.
            if (s <= x) {
                best = max(best, r);
            }
        }

        // Problem guarantees at least one movie fits, so best is always set.
        cout << best << "\n";
    }
    return 0;
}