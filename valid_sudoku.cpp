#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // ans[i] first holds the product of all elements BEFORE index i
        // (the "prefix product").
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Now sweep from the right, multiplying each ans[i] by the
        // product of all elements AFTER index i (the "suffix product"),
        // which is accumulated on the fly in `suffix`.
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

// --- Simple test driver -----------------------------------------------

static void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

static void runTest(vector<int> nums) {
    Solution sol;
    vector<int> input = nums; // keep a copy for printing, since the call may reuse the vector
    vector<int> result = sol.productExceptSelf(nums);
    cout << "Input:  ";
    printVector(input);
    cout << "\nOutput: ";
    printVector(result);
    cout << "\n\n";
}

int main() {
    // LeetCode's own examples
    runTest({1, 2, 3, 4});   // expected [24, 12, 8, 6]
    runTest({-1, 1, 0, -3, 3}); // expected [0, 0, 9, 0, 0]

    // A couple of extra edge cases
    runTest({5});             // single element -> [1]
    runTest({2, 3});          // two elements   -> [3, 2]

    return 0;
}