from typing import List

def minDistance(word1: str, word2: str) -> int:
    m, n = len(word1), len(word2)
    previous = list(range(n + 1))
    for i in range(1, m+1):
        current = [0] * (n + 1)
        current[0] = i

        for j in range(1, n+1):
            if word1[i - 1] == word2[j - 1]:
                current[j] = previous[j - 1]
            else:
                insert = current[j - 1]
                delete = previous[j]
                replace = previous[j - 1]
                current[j] = 1 + min(insert, delete, replace)
        previous = current
    return previous[n]

if __name__ == "__main__":
    print("Testing minDistance function:")
    print("For the input word1 = 'horse', word2 = 'ros', the output is:", minDistance('horse', 'ros')) #Output: 3
    print("For the input word1 = 'intention', word2 = 'execution', the output is:", minDistance('intention', 'execution')) #Output: 5