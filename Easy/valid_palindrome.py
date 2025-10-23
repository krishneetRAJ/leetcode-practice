"""
LeetCode Problem #125: Valid Palindrome
Difficulty: Easy

Problem:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Constraints:
- 1 <= s.length <= 2 * 10^5
- s consists only of printable ASCII characters.
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        Two Pointer Approach
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        left, right = 0, len(s) - 1
        
        while left < right:
            # Skip non-alphanumeric characters from left
            while left < right and not s[left].isalnum():
                left += 1
            
            # Skip non-alphanumeric characters from right
            while left < right and not s[right].isalnum():
                right -= 1
            
            # Compare characters (case-insensitive)
            if s[left].lower() != s[right].lower():
                return False
            
            left += 1
            right -= 1
        
        return True


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1
    s1 = "A man, a plan, a canal: Panama"
    print(f"Test 1: s = \"{s1}\"")
    print(f"Output: {solution.isPalindrome(s1)}")
    print(f"Expected: True\n")
    
    # Test case 2
    s2 = "race a car"
    print(f"Test 2: s = \"{s2}\"")
    print(f"Output: {solution.isPalindrome(s2)}")
    print(f"Expected: False\n")
    
    # Test case 3
    s3 = " "
    print(f"Test 3: s = \"{s3}\"")
    print(f"Output: {solution.isPalindrome(s3)}")
    print(f"Expected: True")
