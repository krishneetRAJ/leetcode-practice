#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char, int> romanMap = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };

            int total = 0;
            for (size_t i = 0; i < s.length(); i++) {
                if (i + 1 < s.length() && romanMap[s[i]] < romanMap[s[i + 1]]) {
                    total -= romanMap[s[i]];
                } else {
                    total += romanMap[s[i]];
                }
            }
            return total;
        }
};

//Example usage:
int main() {
    Solution solution1;
    string roman1 = "III";
    int result1 = solution1.romanToInt(roman1);
    cout << "For the input \"III\", the integer value is: " << result1 << endl;

    Solution solution2;
    string roman2 = "LVIII";
    int result2 = solution2.romanToInt(roman2);
    cout << "For the input \"LVIII\", the integer value is: " << result2 << endl;

    Solution solution3;
    string roman3 = "MCMXCIV";
    int result3 = solution3.romanToInt(roman3);
    cout << "For the input \"MCMXCIV\", the integer value is: " << result3 << endl;
};