#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) {
                return "";
            }
            string prefix = strs[0];
            for (int i = 1; i < strs.size(); i++) {
                while (strs[i].find(prefix) != 0) {
                    prefix = prefix.substr(0, prefix.length() - 1);
                    if (prefix.empty()) {
                        return "";
                    }
                }
            }
            return prefix;
        }
};

// Example usage:
int main() {
    Solution solution1;
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest common prefix of [\"flower\", \"flow\", \"flight\"] is: \"" << solution1.longestCommonPrefix(strs1) << "\"" << endl;

    Solution solution2;
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest common prefix of [\"dog\", \"racecar\", \"car\"] is: \"" << solution2.longestCommonPrefix(strs2) << "\"" << endl;

    return 0;
}