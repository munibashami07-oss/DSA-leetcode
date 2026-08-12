#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // leftMax is the limiting factor on this side
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;

    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1: " << sol.trap(height1) << " (expected 6)" << endl;

    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2: " << sol.trap(height2) << " (expected 9)" << endl;

    vector<int> height3 = {1, 1, 1, 1};
    cout << "Test 3: " << sol.trap(height3) << " (expected 0)" << endl;

    vector<int> height4 = {};
    cout << "Test 4: " << sol.trap(height4) << " (expected 0)" << endl;

    return 0;
}