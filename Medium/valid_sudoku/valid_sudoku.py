from typing import List

def isValidSudoku(self, board: List[List[str]]) -> bool:
    for i in range(9):
        for j in range(9):
            num = board[i][j]
            if num == '.':
                continue
            # Check row
            for k in range(9):
                if k != j and board[i][k] == num:
                    return False
            # Check column
            for k in range(9):
                if k != i and board[k][j] == num:
                    return False
            start_row = (i // 3) * 3
            start_col = (j // 3) * 3
            for r in range(start_row, start_row + 3):
                for c in range(start_col, start_col + 3):
                    if (r != i or c != j) and board[r][c] == num:
                        return False
    return True

if __name__ == "__main__":
    print("Testing isValidSudoku function:")
    board1 = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    print("For the first board, the output is:", isValidSudoku(None, board1)) #Output: True

    board2 = [
        ["8","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    print("For the second board, the output is:", isValidSudoku(None, board2)) #Output: False
        
        