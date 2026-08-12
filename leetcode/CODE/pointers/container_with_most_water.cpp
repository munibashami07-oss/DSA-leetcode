#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.
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