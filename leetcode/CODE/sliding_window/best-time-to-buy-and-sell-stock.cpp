#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPriceSoFar = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < (int)prices.size(); i++) {
            // Option 1: sell today using the lowest price seen so far
            int profitIfSoldToday = prices[i] - minPriceSoFar;
            maxProfit = max(maxProfit, profitIfSoldToday);

            // Option 2: update the lowest price seen so far
            minPriceSoFar = min(minPriceSoFar, prices[i]);
        }

        return maxProfit;
    }
};

// ---------- Test harness ----------
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]";
}

void runTest(vector<int> prices, int expected) {
    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Input: ";
    printVector(prices);
    cout << " -> Output: " << result << " | Expected: " << expected;
    cout << (result == expected ? "  [PASS]" : "  [FAIL]") << endl;
}

int main() {
    runTest({7,1,5,3,6,4}, 5);   // Example 1
    runTest({7,6,4,3,1}, 0);     // Prices strictly decreasing -> no profit
    runTest({}, 0);              // Empty input
    runTest({5}, 0);             // Single day, no transaction possible
    runTest({2,2,2,2}, 0);       // Flat prices
    runTest({1,2}, 1);           // Simple two-day increase
    runTest({2,4,1,7}, 6);       // Buy at 1, sell at 7

    return 0;
}