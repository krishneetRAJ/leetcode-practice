#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            if(s.empty()) {
                return 0;
            }
            // Remove trailing spaces
            vector<string> chunks;
            string word;
            for (char c : s) {
                if (c == ' ') {
                    if (!word.empty()) {
                        chunks.push_back(word);
                        word.clear();
                    }
                } else {
                    word += c;
                }
            }
            if (!word.empty()) {
                chunks.push_back(word);
            }
            if (chunks.empty()) {
                return 0;
            }
            return chunks.back().length();
        }
};

//Example usage:
int main() {
    string input1 = "Hello World";
    Solution solution1;
    int result1 = solution1.lengthOfLastWord(input1);
    cout << "Length of the last word in \"" << input1 << "\": " << result1 << endl;

    string input2 = "   fly me   to   the moon  ";
    Solution solution2;
    int result2 = solution2.lengthOfLastWord(input2);
    cout << "Length of the last word in \"" << input2 << "\": " << result2 << endl;

    string input3 = "luffy is still joyboy";
    Solution solution3;
    int result3 = solution3.lengthOfLastWord(input3);
    cout << "Length of the last word in \"" << input3 << "\": " << result3 << endl;

    return 0;
}