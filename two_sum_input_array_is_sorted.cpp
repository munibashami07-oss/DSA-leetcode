#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return {left + 1, right + 1};

            if (sum < target)
                left++;
            else
                right--;
        }

        return {};
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

static void runTest(vector<int> numbers, int target, vector<int> expected) {
    Solution sol;
    vector<int> input = numbers; // keep a copy for printing
    vector<int> result = sol.twoSum(numbers, target);

    cout << "Input:    numbers = ";
    printVector(input);
    cout << ", target = " << target << "\n";
    cout << "Output:   ";
    printVector(result);
    cout << "\nExpected: ";
    printVector(expected);
    cout << "\n" << (result == expected ? "PASS" : "FAIL") << "\n\n";
}

int main() {
    // LeetCode's own examples (1-indexed answers)
    runTest({2, 7, 11, 15}, 9, {1, 2});
    runTest({2, 3, 4}, 6, {1, 3});
    runTest({-1, 0}, -1, {1, 2});

    // Extra edge cases
    runTest({1, 2, 3, 4, 4, 9}, 8, {4, 5}); // duplicate values summing to target
    runTest({5, 25, 75}, 100, {2, 3});      // answer not at the array's edges

    return 0;
}