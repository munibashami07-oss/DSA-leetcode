#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, X;
        cin >> A >> B >> X;

        cout << (B - A) / X << endl;
    }

    return 0;
}