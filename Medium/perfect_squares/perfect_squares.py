from typing import List

def numSquares(n: int) -> int:
    a = [n] * (n + 1)
    a[0] = 0

    for i in range(1, n+1):
        j = 1
        while (j*j) <= i:
            if(a[i] > a[i - (j*j)] + 1):
                a[i] = a[i-(j*j)] + 1
            j += 1
    return a[n]

if __name__ == "__main__":
    print("Testing numSquares function:")
    print("For n = 12, the output is:", numSquares(12)) #Output: 3
    print("For n = 13, the output is:", numSquares(13)) #Output: 2
