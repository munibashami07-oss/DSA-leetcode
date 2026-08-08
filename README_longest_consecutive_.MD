#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {

            // Start only from the beginning of a sequence
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int length = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

// --- Simple test driver -----------------------------------------------

static void runTest(vector<int> nums, int expected) {
    Solution sol;
    vector<int> input = nums; // keep a copy for printing
    int result = sol.longestConsecutive(nums);

    cout << "Input:    [";
    for (size_t i = 0; i < input.size(); i++) {
        cout << input[i];
        if (i + 1 < input.size()) cout << ", ";
    }
    cout << "]\n";
    cout << "Output:   " << result << "\n";
    cout << "Expected: " << expected << "\n";
    cout << (result == expected ? "PASS" : "FAIL") << "\n\n";
}

int main() {
    // LeetCode's own examples
    runTest({100, 4, 200, 1, 3, 2}, 4);                          // sequence 1,2,3,4
    runTest({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9);                    // sequence 0..8

    // Extra edge cases
    runTest({}, 0);                 // empty array
    runTest({5}, 1);                // single element
    runTest({1, 2, 0, 1}, 3);       // duplicates in the array

    return 0;
}