#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            string result = "";
            int carry = 0;
            int i = a.length() - 1;
            int j = b.length() - 1;

            while (i >= 0 || j >= 0 || carry) {
                int sum = carry;

                if (i >= 0) {
                    sum += a[i] - '0';
                    i--;
                }

                if (j >= 0) {
                    sum += b[j] - '0';
                    j--;
                
                }
                carry = sum / 2;
                result = to_string(sum % 2) + result;
            }

            return result;
        }
};

//Example usage:
int main() {
    Solution solution1;
    string a = "11";
    string b = "1";
    cout << "Sum of \"" << a << "\" and \"" << b << "\" is: \"" << solution1.addBinary(a, b) << "\"" << endl;

    Solution solution2;
    a = "1010";
    b = "1011";
    cout << "Sum of \"" << a << "\" and \"" << b << "\" is: \"" << solution2.addBinary(a, b) << "\"" << endl;
}