#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;   // duplicate found
            }
            seen.insert(num);
        }

        return false;  // all elements are unique
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};

    cout << boolalpha;  //to make the output give answer in alphabets rather than 1 or 0 
    cout << "nums1 has duplicate: " << sol.containsDuplicate(nums1) << endl;
    cout << "nums2 has duplicate: " << sol.containsDuplicate(nums2) << endl;

    return 0;
}