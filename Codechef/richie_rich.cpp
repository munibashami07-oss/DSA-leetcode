// Richie Rich
// Chef aims to be the richest person in Chefland by his new restaurant franchise. Currently, his assets are worth 
// A
// A billion dollars and have no liabilities. He aims to increase his assets by 
// X
// X billion dollars per year.

// Also, all the richest people in Chefland are not planning to grow and maintain their current worth.

// To be the richest person in Chefland, he needs to be worth at least 
// B
// B billion dollars. How many years will it take Chef to reach his goal if his value increases by 
// X
// X billion dollars each year?

// Input
// The first line contains an integer 
// T
// T, the number of test cases. Then the test cases follow.
// Each test case contains a single line of input, three integers 
// A
// A, 
// B
// B, 
// X
// X.
// Output
// For each test case, output in a single line the answer to the problem


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