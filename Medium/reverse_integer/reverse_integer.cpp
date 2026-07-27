#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int maximum = 2147483647;
        int minimum = -2147483647 - 1;

        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (reversed > maximum / 10) {
                return 0;
            }

            if (reversed == maximum / 10 && digit > 7) {
                return 0;
            }

            if (reversed < minimum / 10) {
                return 0;
            }

            if (reversed == minimum / 10 && digit < -8) {
                return 0;
            }

            reversed = reversed * 10 + digit;
        }

        return reversed;
    }
};

// Example usage:
int main() {
    Solution solution;
    int test1 = 123;
    int result1 = solution.reverse(test1);
    cout << "Testing Reverse Integer: " << endl;
    cout << "Input: " << test1 << ", Reversed: " << result1 << endl;    

    int test2 = -123;
    int result2 = solution.reverse(test2);
    cout << "Input: " << test2 << ", Reversed: " << result2 << endl;

    int test3 = 120;
    int result3 = solution.reverse(test3);
    cout << "Input: " << test3 << ", Reversed: " << result3 << endl;

    return 0;
};