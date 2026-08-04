#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Returns the index of the first element that is a duplicate
    // of some earlier element, or -1 if no duplicates exist.
    int firstDuplicateIndex(vector<int>& nums) {
        unordered_map<int, int> seen; // value -> first index it appeared at

        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                return i;   // nums[i] was already seen earlier -> duplicate found here
            }
            seen[nums[i]] = i;  // record first occurrence
        }

        return -1;  // no duplicates
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {5, 1, 5, 1};

    cout << "nums1 first duplicate index: " << sol.firstDuplicateIndex(nums1) << endl;
    cout << "nums2 first duplicate index: " << sol.firstDuplicateIndex(nums2) << endl;
    cout << "nums3 first duplicate index: " << sol.firstDuplicateIndex(nums3) << endl;

    return 0;
}