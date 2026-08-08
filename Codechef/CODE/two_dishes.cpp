#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;

        // Dish type 1 needs 1 fruit + 1 vegetable.
        // Dish type 2 needs 1 vegetable + 1 fish.
        // If Chef makes x dishes of type 1 and y of type 2:
        //   x <= A   (fruit limit)
        //   y <= C   (fish limit)
        //   x + y <= B   (vegetable limit)
        // Total dishes x + y is maximized by using as many fruits and
        // fishes as possible (each one only helps up to the vegetable
        // cap), so the maximum achievable total is min(A + C, B).
        long long maxDishes = min(a + c, b);

        cout << (maxDishes >= n ? "YES" : "NO") << "\n";
    }
    return 0;
}