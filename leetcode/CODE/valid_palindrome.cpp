#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left]))
                left++;

            while (left < right && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};

// --- Simple test driver -----------------------------------------------

static void runTest(string s, bool expected) {
    Solution sol;
    string input = s; // keep a copy for printing, in case it gets mutated
    bool result = sol.isPalindrome(s);

    cout << "Input:    \"" << input << "\"\n";
    cout << "Output:   " << (result ? "true" : "false") << "\n";
    cout << "Expected: " << (expected ? "true" : "false") << "\n";
    cout << (result == expected ? "PASS" : "FAIL") << "\n\n";
}

int main() {
    // LeetCode's own examples
    runTest("A man, a plan, a canal: Panama", true);
    runTest("race a car", false);
    runTest(" ", true); // only non-alphanumeric characters -> empty after filtering

    // Extra edge cases
    runTest("", true);                 // empty string
    runTest("0P", false);               // single alnum pair, mismatched
    runTest("Was it a car or a cat I saw?", true); // mixed case + punctuation

    return 0;
}