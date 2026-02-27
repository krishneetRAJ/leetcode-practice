from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def is_safe(row, col):
            # Check column
            for r in range(row):
                if board[r][col] == "Q":
                    return False

            # Check upper-left diagonal
            r, c = row - 1, col - 1
            while r >= 0 and c >= 0:
                if board[r][c] == "Q":
                    return False
                r -= 1
                c -= 1

            # Check upper-right diagonal
            r, c = row - 1, col + 1
            while r >= 0 and c < n:
                if board[r][c] == "Q":
                    return False
                r -= 1
                c += 1

            return True

        def backtrack(row):
            if row == n:
                result.append(["".join(r) for r in board])
                return

            for col in range(n):
                if is_safe(row, col):
                    board[row][col] = "Q"
                    backtrack(row + 1)
                    board[row][col] = "."

        board = [["."] * n for _ in range(n)]
        result = []
        backtrack(0)
        return result
    
# Example usage:
if __name__ == "__main__":
    solution1 = Solution()
    solutions = solution1.solveNQueens(4)
    print("Testing solveNQueens function:")
    print("For n = 4, the solutions are:")
    print(solutions)
    
    print("")
    solution2 = Solution()
    solutions = solution2.solveNQueens(1)
    print("For n = 1, the solutions are:")
    print(solutions)