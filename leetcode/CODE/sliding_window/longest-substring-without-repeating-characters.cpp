#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int maxLen = 0, left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (lastIndex.count(c) && lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Length of longest substring without repeating characters: "
         << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}