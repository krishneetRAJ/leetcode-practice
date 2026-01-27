#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t){
            if (s.empty() || t.empty()){
                return "";
            }

            unordered_map<char, int> dict_t; // Frequency map for characters in t
            for (char c : t) {
                dict_t[c]++; // Count frequency of each character in t
            }

            unordered_map<char, int> window_counts;
            int required = dict_t.size();
            int formed = 0;

            int l = 0;
            int minLen = s.length() + 1;
            int minStart = 0;

            for (int r = 0; r < s.length(); r++) {
                char c = s[r];
                window_counts[c]++;

                if (dict_t.count(c) && window_counts[c] == dict_t[c]) { // Character c is now fully matched
                    formed++;
                }

                while (l <= r && formed == required) { // Try to contract the window
                    if (r - l + 1 < minLen) {
                        minLen = r - l + 1;
                        minStart = l;
                    }

                    char leftChar = s[l];
                    window_counts[leftChar]--;
 
                    if (dict_t.count(leftChar) && window_counts[leftChar] < dict_t[leftChar]) { // Character leftChar is no longer fully matched
                        formed--;
                    }

                    l++;
                }
            }

            if (minLen > s.length()) { // No valid window found
                return "";
            }

        return s.substr(minStart, minLen);
    }
};

int main() {
    Solution sol;

    string s, t;

    s = "ADOBECODEBANC";
    t = "ABC";
    cout << "For the input of s = \"" << s << "\" and t = \"" << t << "\":" << endl;
    cout << "\"" << sol.minWindow(s, t) << "\"" << endl; // BANC

    s = "a";
    t = "a";
    cout << "For the input of s = \"" << s << "\" and t = \"" << t << "\":" << endl;
    cout << "\"" << sol.minWindow(s, t) << "\"" << endl; // "a"

    s = "a";
    t = "aa";
    cout << "For the input of s = \"" << s << "\" and t = \"" << t << "\":" << endl;
    cout << "\"" << sol.minWindow(s, t) << "\"" << endl; // ""

    return 0;
}