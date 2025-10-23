/*
LeetCode Problem #15: 3Sum
Difficulty: Medium

Problem:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = [0,1,1]
Output: []

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]

Constraints:
- 3 <= nums.length <= 3000
- -10^5 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Two Pointer Approach with Sorting
     * Time Complexity: O(n^2)
     * Space Complexity: O(1) excluding output
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                
                if (total < 0) {
                    left++;
                } else if (total > 0) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for second element
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // Skip duplicates for third element
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
};

// Helper function to print 2D vector
void print2DVector(const vector<vector<int>>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "[";
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
            if (j < vec[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test 1: nums = [-1, 0, 1, 2, -1, -4]" << endl;
    cout << "Output: ";
    print2DVector(solution.threeSum(nums1));
    cout << endl << "Expected: [[-1, -1, 2], [-1, 0, 1]]" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 1, 1};
    cout << "Test 2: nums = [0, 1, 1]" << endl;
    cout << "Output: ";
    print2DVector(solution.threeSum(nums2));
    cout << endl << "Expected: []" << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {0, 0, 0};
    cout << "Test 3: nums = [0, 0, 0]" << endl;
    cout << "Output: ";
    print2DVector(solution.threeSum(nums3));
    cout << endl << "Expected: [[0, 0, 0]]" << endl;
    
    return 0;
}
