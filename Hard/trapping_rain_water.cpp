/*
LeetCode Problem #42: Trapping Rain Water
Difficulty: Hard

Problem:
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
- n == height.length
- 1 <= n <= 2 * 10^4
- 0 <= height[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Two Pointer Approach
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        
        int left = 0, right = height.size() - 1;
        int left_max = height[left], right_max = height[right];
        int water = 0;
        
        while (left < right) {
            if (left_max < right_max) {
                left++;
                left_max = max(left_max, height[left]);
                water += left_max - height[left];
            } else {
                right--;
                right_max = max(right_max, height[right]);
                water += right_max - height[right];
            }
        }
        
        return water;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1: height = ";
    printVector(height1);
    cout << endl << "Output: " << solution.trap(height1) << endl;
    cout << "Expected: 6" << endl << endl;
    
    // Test case 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2: height = ";
    printVector(height2);
    cout << endl << "Output: " << solution.trap(height2) << endl;
    cout << "Expected: 9" << endl;
    
    return 0;
}
