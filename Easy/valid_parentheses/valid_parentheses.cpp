#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> bracketStack;
            for(int i = 0; i < s.size(); i++) {
                char c = s[i];
                if(c == '(' || c == '{' || c == '[') {
                    bracketStack.push(c);
                }
                else {
                    if(bracketStack.empty()) {
                        return false;
                    }
                    char top = bracketStack.top();
                    bracketStack.pop();
                    if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                        return false;
                    }
                }
            }
            return bracketStack.empty();
        }
};

//Example usage:
int main() {
    cout << boolalpha; //Print boolean values as true/false
    cout << "Testing Valid Parentheses: " << endl;
    Solution solution1;
    string s1 = "()";
    cout << "Input: " << s1 << " - Output: " << solution1.isValid(s1) << endl;

    string s2 = "()[]{}";
    cout << "Input: " << s2 << " - Output: " << solution1.isValid(s2) << endl;

    string s3 = "(]";
    cout << "Input: " << s3 << " - Output: " << solution1.isValid(s3) << endl;

    string s4 = "([)]";
    cout << "Input: " << s4 << " - Output: " << solution1.isValid(s4) << endl;

    string s5 = "{[]}";
    cout << "Input: " << s5 << " - Output: " << solution1.isValid(s5) << endl;  
}