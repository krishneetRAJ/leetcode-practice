#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> variables;
        return solve(expression, variables);
    }

    int parseNumber(const string& expr) const {
        int result = 0;
        int i = 0;
        int sign = 1;
        if (expr[0] == '-') {
            sign = -1;
            i = 1;
        }
        const int n = static_cast<int>(expr.size());
        for (int pos = i; pos < n; pos++) {
            result = result * 10 + (expr[pos] - '0');
        }
        return result * sign;
    }

    int solve(string expr, unordered_map<string, int> variables) {
        if (expr[0] != '(') {
            if (expr[0] == '-' || (expr[0] >= '0' && expr[0] <= '9')) {
                return parseNumber(expr);
            }

            return variables[expr];
        }

        // Remove outer parentheses
        expr = expr.substr(1, expr.size() - 2);

        vector<string> parts;
        string current = "";
        int depth = 0;

        for (int i = 0; i < expr.size(); i++) {
            char c = expr[i];

            if (c == '(') {
                depth++;
            }
            else if (c == ')') {
                depth--;
            }
            if (c == ' ' && depth == 0) {
                parts.push_back(current);
                current = "";
            }
            else {
                current += c;
            }
        }

        parts.push_back(current);
        string operation = parts[0];

        if (operation == "add") {
            return solve(parts[1], variables) + solve(parts[2], variables);
        }
        if (operation == "mult") {
            return solve(parts[1], variables) * solve(parts[2], variables);
        }
        if (operation == "let") {
            for (int i = 1; i < parts.size() - 1; i += 2) {
                variables[parts[i]] = solve(parts[i + 1], variables);
            }
            return solve(parts.back(), variables);
        }
        return 0;
    }
};

// Example usage:
int main() {
    Solution solution1;
    string expression1 = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
    int result1 = solution1.evaluate(expression1);
    cout << "For the input expression '(let x 2 (mult x (let x 3 y 4 (add x y))))', the result is: " << result1 << endl;

    Solution solution2;
    string expression2 = "(let x 3 x 2 x)";
    int result2 = solution2.evaluate(expression2);
    cout << "For the input expression '(let x 3 x 2 x)', the result is: " << result2 << endl;

    Solution solution3;
    string expression3 = "(let x 1 y 2 x (add x y) (add x y))";
    int result3 = solution3.evaluate(expression3);
    cout << "For the input expression '(let x 1 y 2 x (add x y) (add x y))', the result is: " << result3 << endl;
    return 0;
}