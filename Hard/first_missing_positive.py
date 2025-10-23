"""
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
"""

from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        """
        Index as Hash Key Approach
        Time Complexity: O(n)
        Space Complexity: O(1)
        
        The idea is to use the array itself as a hash table.
        We place each number in its correct position (num at index num-1).
        """
        n = len(nums)
        
        # Step 1: Place each number in its correct position
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                # Swap nums[i] with nums[nums[i] - 1]
                correct_pos = nums[i] - 1
                nums[i], nums[correct_pos] = nums[correct_pos], nums[i]
        
        # Step 2: Find the first position where number doesn't match
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        
        # If all positions are correct, return n + 1
        return n + 1


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1
    nums1 = [1, 2, 0]
    print(f"Test 1: nums = {nums1}")
    print(f"Output: {solution.firstMissingPositive(nums1.copy())}")
    print(f"Expected: 3\n")
    
    # Test case 2
    nums2 = [3, 4, -1, 1]
    print(f"Test 2: nums = {nums2}")
    print(f"Output: {solution.firstMissingPositive(nums2.copy())}")
    print(f"Expected: 2\n")
    
    # Test case 3
    nums3 = [7, 8, 9, 11, 12]
    print(f"Test 3: nums = {nums3}")
    print(f"Output: {solution.firstMissingPositive(nums3.copy())}")
    print(f"Expected: 1")
