#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            maxWater = max(maxWater, width * h);

            // Move the pointer at the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    Solution sol;

    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << sol.maxArea(height1) << " (expected 49)" << endl;

    vector<int> height2 = {1, 1};
    cout << "Test 2: " << sol.maxArea(height2) << " (expected 1)" << endl;

    vector<int> height3 = {4, 3, 2, 1, 4};
    cout << "Test 3: " << sol.maxArea(height3) << " (expected 16)" << endl;}