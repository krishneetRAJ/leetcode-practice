from typing import List

def numDistinct(s: str, t: str) -> int:
    ways = [0] * (len(t) + 1)
    ways[0] = 1

    for char in s:
        for j in range(len(t) - 1, -1, -1):
            if char == t[j]:
                ways[j + 1] += ways[j]

    return ways[len(t)]

if __name__ == "__main__":
    print("Testing numDistinct function:")
    s = "rabbbit"
    t = "rabbit"
    print(f"For the input s = '{s}' and t = '{t}', the output is: {numDistinct(s, t)}")

    s = "babgbag"
    t = "bag"
    print(f"For the input s = '{s}' and t = '{t}', the output is: {numDistinct(s, t)}")