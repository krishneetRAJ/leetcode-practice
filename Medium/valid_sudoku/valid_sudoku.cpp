#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board){
            for(int i = 0; i < 9; i++){
                unordered_set<char> seen;
                for(int j = 0; j < 9; j++){
                    char current = board[i][j];
                    if(current == '.'){
                        continue;
                    }
                    if(seen.count(current)){
                        return false;
                    }
                    seen.insert(current);
                }
            }
            for(int j = 0; j < 9; j++){
                unordered_set<char> seen;
                for(int i = 0; i < 9; i++){
                    char current = board[i][j];
                    if(current == '.'){
                        continue;
                    }
                    if(seen.count(current)){
                        return false;
                    }
                    seen.insert(current);
                }
            }
            for(int boxCol = 0; boxCol < 9; boxCol = boxCol + 3) {
                for(int boxRow = 0; boxRow < 9; boxRow = boxRow + 3){
                    unordered_set<char> seen;
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            char current = board[boxRow + i][boxCol + j];
                            if(current == '.'){
                                continue;
                            }
                            if(seen.count(current)){
                                return false;
                            }
                            seen.insert(current);
                        }
                    }
                }
            }
        return true;
    }
};

// Example usage:
int main(){
    Solution solution;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << boolalpha; 
    bool result = solution.isValidSudoku(board);
    cout << "For the first board, the Sudoku board output is " << result << "." << endl;

    vector<vector<char>> board2 = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << boolalpha;
    bool result2 = solution.isValidSudoku(board2);
    cout << "For the second board, the Sudoku board output is " << result2 << "." << endl;
}