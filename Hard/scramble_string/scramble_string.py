from typing import List

def isScramble(s1: str, s2: str) -> bool:
        memo = {}

        def solve(a, b):
            if a == b:
                return True

            key = (a, b)

            if key in memo:
                return memo[key]

            if sorted(a) != sorted(b):
                memo[key] = False
                return False

            n = len(a)

            for i in range(1, n):
                # No swap
                if solve(a[:i], b[:i]) and solve(a[i:], b[i:]):
                    memo[key] = True
                    return True

                # Swap
                if solve(a[:i], b[n - i:]) and solve(a[i:], b[:n - i]):
                    memo[key] = True
                    return True

            memo[key] = False
            return False

        return solve(s1, s2)

if __name__ == "__main__":
    print("Testing isScramble function:")
    test_case_1 = ("great", "rgeat")
    print(f"For the input {test_case_1}, the output is:", isScramble(*test_case_1)) #Output: True

    test_case_2 = ("abcde", "caebd")
    print(f"For the input {test_case_2}, the output is:", isScramble(*test_case_2)) #Output: False

    test_case_3 = ("a", "a")
    print(f"For the input {test_case_3}, the output is:", isScramble(*test_case_3)) #Output: True