#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};   // found the pair
            }

            seen[nums[i]] = i;  // record this value's index for future lookups
        }

        return {};  // no valid pair found
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);

    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);

    // helper to print
    auto printResult = [](const vector<int>& res) {
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i + 1 < res.size()) cout << ", ";
        }
        cout << "]" << endl;
    };

    printResult(result1); // [0, 1]
    printResult(result2); // [1, 2]
    printResult(result3); // [0, 1]

    return 0;
}