from typing import List

def numIslands(grid: List[List[str]]) -> int:
    if not grid:
        return 0
    rows = len(grid)
    cols = len(grid[0])
    count = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "1":
                count += 1
                stack = []
                stack.append([r, c])
                while len(stack) > 0:
                    cell = stack.pop()
                    current_row = cell[0]
                    current_col = cell[1]

                    if grid[current_row][current_col] == "0":
                        continue
                    grid[current_row][current_col] = "0"

                    new_r = current_row - 1
                    new_c = current_col
                    if new_r >= 0:                
                        if grid[new_r][new_c] == "1":
                            stack.append([new_r, new_c])

                    new_r = current_row + 1
                    new_c = current_col
                    if new_r < rows:               
                        if grid[new_r][new_c] == "1":
                            stack.append([new_r, new_c])

                    new_r = current_row
                    new_c = current_col - 1
                    if new_c >= 0:                 
                        if grid[new_r][new_c] == "1":
                            stack.append([new_r, new_c])

                    new_r = current_row
                    new_c = current_col + 1
                    if new_c < cols:               
                        if grid[new_r][new_c] == "1":
                            stack.append([new_r, new_c])
    return count
    
if __name__ == "__main__":
    print("Testing numIslands function:")
    grid1 = [
      ["1","1","1","1","0"],
      ["1","1","0","1","0"],
      ["1","1","0","0","0"],
      ["0","0","0","0","0"]
    ]
    print("For the input grid1, the number of islands is:", numIslands(grid1)) #Output: 1

    grid2 = [
      ["1","1","0","0","0"],
      ["1","1","0","0","0"],
      ["0","0","1","0","0"],
      ["0","0","0","1","1"]
    ]
    print("For the input grid2, the number of islands is:", numIslands(grid2)) #Output: 3