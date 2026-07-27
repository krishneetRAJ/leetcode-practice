from typing import List

def totalNQueens(n: int) -> int:
    columns = set()
    diagonal1 = set() # row - col
    diagonal2 = set() # row + col

    def backtrack(row):
        if row == n:
            return 1
        count = 0
        for col in range(n):
            if col in columns:
                continue
            if (row - col) in diagonal1:
                continue
            if (row + col) in diagonal2:
                continue
            columns.add(col)
            diagonal1.add(row - col)
            diagonal2.add(row + col)
            count += backtrack(row + 1)
            columns.remove(col)
            diagonal1.remove(row - col)
            diagonal2.remove(row + col)
        return count
    return backtrack(0)

# Example usage:
if __name__ == "__main__":
    print("Testing totalNQueens function:")
    print("For n = 4, the number of distinct solutions is:", totalNQueens(4))  # Output: 2
    print("For n = 1, the number of distinct solutions is:", totalNQueens(1))  # Output: 1