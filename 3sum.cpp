#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate second elements
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate third elements
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};

// --- Simple test driver -----------------------------------------------

static void printTriplets(vector<vector<int>> triplets) {
    // Sort for stable, order-independent comparison/printing.
    sort(triplets.begin(), triplets.end());
    cout << "[";
    for (size_t i = 0; i < triplets.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < triplets[i].size(); j++) {
            cout << triplets[i][j];
            if (j + 1 < triplets[i].size()) cout << ", ";
        }
        cout << "]";
        if (i + 1 < triplets.size()) cout << ", ";
    }
    cout << "]";
}

static void runTest(vector<int> nums, vector<vector<int>> expected) {
    Solution sol;
    vector<int> input = nums; // keep a copy for printing
    vector<vector<int>> result = sol.threeSum(nums);

    // Sort both for order-independent comparison, since 3Sum's answer
    // order (and the order of numbers within each triplet) isn't fixed.
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());

    cout << "Input:    ";
    cout << "[";
    for (size_t i = 0; i < input.size(); i++) {
        cout << input[i];
        if (i + 1 < input.size()) cout << ", ";
    }
    cout << "]\n";

    cout << "Output:   ";
    printTriplets(result);
    cout << "\nExpected: ";
    printTriplets(expected);
    cout << "\n" << (result == expected ? "PASS" : "FAIL") << "\n\n";
}

int main() {
    // LeetCode's own examples
    runTest({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
    runTest({0, 1, 1}, {});
    runTest({0, 0, 0}, {{0, 0, 0}});

    // Extra edge cases
    runTest({}, {});                          // empty array
    runTest({0, 0, 0, 0}, {{0, 0, 0}});        // many duplicate zeros

    return 0;
}