from typing import List

def countDigitOne(n: int) -> int:
        count = 0
        factor = 1

        while factor <= n:
            lower = n % factor
            current = (n // factor) % 10
            higher = n // (factor * 10)

            if current == 0:
                count += higher * factor

            elif current == 1:
                count += higher * factor + lower + 1

            else:
                count += (higher + 1) * factor

            factor *= 10

        return count

if __name__ == "__main__":
    print("Testing countDigitOne function:")
    test_case_1 = 13
    print(f"For the input {test_case_1}, the output is:", countDigitOne(test_case_1)) #Output: 6

    test_case_2 = 0
    print(f"For the input {test_case_2}, the output is:", countDigitOne(test_case_2)) #Output: 0