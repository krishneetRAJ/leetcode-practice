"""
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
"""

from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """
        Two Pointer Approach with Sorting
        Time Complexity: O(n^2)
        Space Complexity: O(1) excluding output
        """
        nums.sort()
        result = []
        
        for i in range(len(nums) - 2):
            # Skip duplicates for first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            left, right = i + 1, len(nums) - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if total < 0:
                    left += 1
                elif total > 0:
                    right -= 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    
                    # Skip duplicates for second element
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    
                    # Skip duplicates for third element
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    
                    left += 1
                    right -= 1
        
        return result


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1
    nums1 = [-1, 0, 1, 2, -1, -4]
    print(f"Test 1: nums = {nums1}")
    print(f"Output: {solution.threeSum(nums1)}")
    print(f"Expected: [[-1, -1, 2], [-1, 0, 1]]\n")
    
    # Test case 2
    nums2 = [0, 1, 1]
    print(f"Test 2: nums = {nums2}")
    print(f"Output: {solution.threeSum(nums2)}")
    print(f"Expected: []\n")
    
    # Test case 3
    nums3 = [0, 0, 0]
    print(f"Test 3: nums = {nums3}")
    print(f"Output: {solution.threeSum(nums3)}")
    print(f"Expected: [[0, 0, 0]]")
