from typing import List

def setZeroes(matrix: List[List[int]]) -> None:
    if not matrix:
        return
    
    rows, cols = set(), set()
    for i in range(len(matrix)):
        for j in range(len(matrix[0])): #Checking the first row and first column for zeroes
            if matrix[i][j] == 0:
                rows.add(i)
                cols.add(j)

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if i in rows or j in cols:
                matrix[i][j] = 0

if __name__ == "__main__":
    print("Testing setZeroes function:")
    matrix1 = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    print("For the input matrix:")
    for row in matrix1:
        print(row)
    setZeroes(matrix1)
    print("\n")
    print("The output matrix is:")
    for row in matrix1:
        print(row)

    print("\n")

    matrix2 = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    print("For the input matrix:")
    for row in matrix2:
        print(row)
    setZeroes(matrix2)
    print("\n")
    print("The output matrix is:")
    for row in matrix2:
        print(row)
    

