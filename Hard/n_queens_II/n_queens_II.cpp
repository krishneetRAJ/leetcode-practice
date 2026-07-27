#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
    public:
        int totalNQueens(int n) {
            vector<int> queens(n, -1);
            int row = 0;
            int column = 0;
            int count = 0;

            while(row >= 0) {
                bool queenPlaced = false;
                while(column < n) {
                    bool safe = true;
                    for(int previousRow = 0; previousRow < row; previousRow++) {
                        bool sameColumn = queens[previousRow] == column;
                        bool sameDiagonal = abs(queens[previousRow] - column) == row - previousRow;
                        if(sameColumn || sameDiagonal) {
                            safe = false;
                            break;
                        }
                    }
                    if(safe) {
                        queens[row] = column;
                        if(row == n - 1) {
                            count++;
                            column++;
                        }
                        else {
                            row++;
                            column = 0;
                        }
                        queenPlaced = true;
                        break;
                    }
                    column++;
                }
                if(!queenPlaced && column == n) {
                    queens[row] = -1;
                    row--;
                    if(row >= 0) {
                        column = queens[row] + 1;
                        queens[row] = -1;
                    }
                }
            }
            return count;
        }
};

// Example usage:
int main() {
    Solution solution;
    int n1 = 4;
    int result1 = solution.totalNQueens(n1);
    cout << "Testing N-Queens II: " << endl;
    cout << "Input: n = " << n1 << endl; 
    cout << "Output: " << result1 << endl;

    cout << "" << endl;
    int n2 = 1;
    int result2 = solution.totalNQueens(n2);
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << result2 << endl;

    return 0;
}