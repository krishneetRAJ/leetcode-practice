/*
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
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    /**
     * Two Pointer Approach
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "A man, a plan, a canal: Panama";
    cout << "Test 1: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << (solution.isPalindrome(s1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 2
    string s2 = "race a car";
    cout << "Test 2: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << (solution.isPalindrome(s2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test case 3
    string s3 = " ";
    cout << "Test 3: s = \"" << s3 << "\"" << endl;
    cout << "Output: " << (solution.isPalindrome(s3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    
    return 0;
}
