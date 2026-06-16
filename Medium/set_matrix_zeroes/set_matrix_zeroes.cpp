#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            bool row = false;
            bool col = false;
            for(int i = 0; i < n; i++) {
                if(matrix[0][i] == 0) {
                    row = true;
                    break;
                }
            }
            for(int i = 0; i < m; i++) {
                if(matrix[i][0] == 0) {
                    col = true;
                    break;
                }
            }
            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    if(matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
            if(row) {
                for(int i = 0; i < n; i++) {
                    matrix[0][i] = 0;
                }
            }
            if(col) {
                for(int i = 0; i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
        }
};

//Example usage:
int main() {
    Solution solution1;
    vector<vector<int>> matrix1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    solution1.setZeroes(matrix1);
    cout << "Testing Set Matrix Zeroes: " << endl;
    cout << "Input: matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]" << endl;
    cout << "Output: [[";
    for(int i = 0; i < matrix1.size(); i++) {
        for(int j = 0; j < matrix1[0].size(); j++) {
            cout << matrix1[i][j];
            if(j != matrix1[0].size() - 1) {
                cout << ", ";
            }
        }
        if(i != matrix1.size() - 1) {
            cout << "], [";
        }
    }
    cout << "]]" << endl;

    cout << "" << endl;

    Solution solution2;
    vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    solution2.setZeroes(matrix2);
    cout << "Input: matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]" << endl;
    cout << "Output: [[";
    for(int i = 0; i < matrix2.size(); i++) {
        for(int j = 0; j < matrix2[0].size(); j++) {
            cout << matrix2[i][j];
            if(j != matrix2[0].size() - 1) {
                cout << ", ";
            }
        }
        if(i != matrix2.size() - 1) {
            cout << "], [";
        }
    }
    cout << "]]" << endl;
}