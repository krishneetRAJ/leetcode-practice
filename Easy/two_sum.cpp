/*
LeetCode Problem #1: Two Sum
Difficulty: Easy

Problem:
Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Constraints:
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * Hash Map Approach
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        
        return {};
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
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Test 1: nums = ";
    printVector(nums1);
    cout << ", target = " << target1 << endl;
    cout << "Output: ";
    printVector(solution.twoSum(nums1, target1));
    cout << endl << "Expected: [0, 1]" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    cout << "Test 2: nums = ";
    printVector(nums2);
    cout << ", target = " << target2 << endl;
    cout << "Output: ";
    printVector(solution.twoSum(nums2, target2));
    cout << endl << "Expected: [1, 2]" << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    cout << "Test 3: nums = ";
    printVector(nums3);
    cout << ", target = " << target3 << endl;
    cout << "Output: ";
    printVector(solution.twoSum(nums3, target3));
    cout << endl << "Expected: [0, 1]" << endl;
    
    return 0;
}
