/*
LeetCode Problem #41: First Missing Positive
Difficulty: Hard

Problem:
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:
- 1 <= nums.length <= 10^5
- -2^31 <= nums[i] <= 2^31 - 1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Index as Hash Key Approach
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     * 
     * The idea is to use the array itself as a hash table.
     * We place each number in its correct position (num at index num-1).
     */
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Place each number in its correct position
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap nums[i] with nums[nums[i] - 1]
                int correct_pos = nums[i] - 1;
                swap(nums[i], nums[correct_pos]);
            }
        }
        
        // Step 2: Find the first position where number doesn't match
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all positions are correct, return n + 1
        return n + 1;
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
    vector<int> nums1 = {1, 2, 0};
    cout << "Test 1: nums = ";
    printVector(nums1);
    cout << endl << "Output: " << solution.firstMissingPositive(nums1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {3, 4, -1, 1};
    cout << "Test 2: nums = ";
    printVector(nums2);
    cout << endl << "Output: " << solution.firstMissingPositive(nums2) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {7, 8, 9, 11, 12};
    cout << "Test 3: nums = ";
    printVector(nums3);
    cout << endl << "Output: " << solution.firstMissingPositive(nums3) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}
