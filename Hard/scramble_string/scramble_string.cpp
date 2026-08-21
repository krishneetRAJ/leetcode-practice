#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        unordered_map<string, bool> memo;
        bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        if (s1 == s2) {
            return true;
        }

        string key = s1 + "#" + s2;

        if (memo.count(key)) {
            return memo[key];
        }

        // Check if both strings have the same character counts
        unordered_map<char, int> countMap;

        for (char c : s1) {
            countMap[c]++;
        }

        for (char c : s2) {
            countMap[c]--;

            if (countMap[c] < 0) {
                memo[key] = false;
                return false;
            }
        }

        int n = s1.length();

        for (int i = 1; i < n; i++) {
            // No swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {

                memo[key] = true;
                return true;
            }

            // Swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {

                memo[key] = true;
                return true;
            }
        }

        memo[key] = false;
        return false;
    }
};

// Example usage:
int main() {
    Solution solution1;
    string s1_1 = "great";
    string s2_1 = "rgeat";
    bool result1 = solution1.isScramble(s1_1, s2_1);
    cout << boolalpha;
    cout << "Input: s1 = \"" << s1_1 << "\", s2 = \"" << s2_1 << "\"" << endl;
    cout << "Output: " << result1 << endl;

    Solution solution2;
    string s1_2 = "abcde";
    string s2_2 = "caebd";
    bool result2 = solution2.isScramble(s1_2, s2_2);
    cout << endl;
    cout << "Input: s1 = \"" << s1_2 << "\", s2 = \"" << s2_2 << "\"" << endl;
    cout << "Output: " << result2 << endl;

    Solution solution3;
    string s1_3 = "a";
    string s2_3 = "a";
    bool result3 = solution3.isScramble(s1_3, s2_3);
    cout << endl;
    cout << "Input: s1 = \"" << s1_3 << "\", s2 = \"" << s2_3 << "\"" << endl;
    cout << "Output: " << result3 << endl;

    return 0;
}