#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    public:
        vector<string> removeInvalidParentheses(string s) {
            vector<string> result;
            unordered_set<string> visited;
            queue<string> q;
            bool found = false;

            q.push(s);
            visited.insert(s);

            while (!q.empty()) {
                int levelSize = q.size();

                for (int k = 0; k < levelSize; k++) {
                    string current = q.front();
                    q.pop();

                    // Check if the current string is valid
                    int balance = 0;
                    bool valid = true;

                    for (int i = 0; i < current.length(); i++) {
                        if (current[i] == '(') {
                            balance++;
                        }
                        else if (current[i] == ')') {
                            balance--;
                        }

                        if (balance < 0) {
                            valid = false;
                            break;
                        }
                    }

                    if (balance != 0) {
                        valid = false;
                    }

                    if (valid) {
                        result.push_back(current);
                        found = true;
                    }

                    // Don't generate more strings once a valid level is found
                    if (found) {
                        continue;
                    }

                    for (int i = 0; i < current.length(); i++) {
                        if (current[i] != '(' && current[i] != ')') {
                            continue;
                        }

                        string newString = current.substr(0, i) + current.substr(i + 1);

                        if (visited.count(newString) == 0) {
                            visited.insert(newString);
                            q.push(newString);
                        }
                    }
                }
                if (found) {
                    break;
                }
            }
            return result;
        }
};

// Example usage:
int main() {
    Solution solution1;
    string s1 = "()())()";
    vector<string> result1 = solution1.removeInvalidParentheses(s1);
    cout << "Testing Remove Invalid Parentheses: " << endl;
    cout << "Input: " << s1 << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i != result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    Solution solution2;
    string s2 = "(a)())()";
    vector<string> result2 = solution2.removeInvalidParentheses(s2);
    cout << "" << endl;
    cout << "Input: " << s2 << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i != result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;        

    Solution solution3;
    string s3 = ")(";
    vector<string> result3 = solution3.removeInvalidParentheses(s3);
    cout << "" << endl;
    cout << "Input: " << s3 << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i != result3.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}