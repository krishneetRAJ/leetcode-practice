#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0 || (x % 10 == 0 && x != 0)) {
                return false;
            }
            int reversed_half = 0;
            while(x > reversed_half) {
                reversed_half = reversed_half * 10 + x % 10;
                x /= 10;
            }
            if(x == reversed_half || x == reversed_half / 10) {
                return true;
            }
            return false;
    }
};

//Example usage:
int main() {
    cout << boolalpha; //Print boolean values as true/false
    cout << "Testing Palindrome Number: " << endl;
    Solution solution1;
    int num1 = 121;
    cout << "Input: " << num1 << " - Output: " << solution1.isPalindrome(num1) << endl; // true

    int num2 = -121;
    cout << "Input: " << num2 << " - Output: " << solution1.isPalindrome(num2) << endl; // false

    int num3 = 10;
    cout << "Input: " << num3 << " - Output: " << solution1.isPalindrome(num3) << endl; // false
}