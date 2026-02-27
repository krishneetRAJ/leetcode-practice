#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board, result);
        return result;
    }

    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                backtrack(row + 1, n, board, result);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, int n, vector<string>& board) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};

// Example usage:
int main() {
    Solution solution1;
    int n = 4;
    vector<vector<string>> result = solution1.solveNQueens(n);

    cout << "Testing N-Queens with n = 4:" << endl;
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    cout << "";
    cout << "Testing N-Queens with n = 1:" << endl;
    Solution solution2;
    int n2 = 1;
    vector<vector<string>> result2 = solution2.solveNQueens(n2);
    cout << "[";
    for (int i = 0; i < result2.size(); i++) {
        cout << "[";
        for (int j = 0; j < result2[i].size(); j++)
            cout << "\"" << result2[i][j] << "\"";
        cout << "]";
        if (i < result2.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}