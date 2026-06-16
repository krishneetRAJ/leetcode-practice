from typing import List

def getPermutation(n: int, k: int) -> str:
    # Create a list of numbers to get permutations from
    numbers = list(range(1, n + 1))
    # Calculate the factorial of (n-1) to determine the block size
    factorial = 1
    for i in range(1, n):
        factorial *= i

    # Adjust k to be zero-indexed
    k -= 1

    result = []
    for i in range(n):
        index = k // factorial
        result.append(str(numbers[index]))
        # Remove the used number from the list
        numbers.pop(index)

        if i < n - 1:
            k %= factorial
            factorial //= (n - 1 - i)

    return "".join(result)

if __name__ == "__main__":
    print("Testing getPermutation function:")
    print("For n = 3 and k = 3, the output is:", getPermutation(3, 3)) #Output: "213"
    print("For n = 4 and k = 9, the output is:", getPermutation(4, 9)) #Output: "2314"
    print("For n = 3 and k = 1, the output is:", getPermutation(3, 1)) #Output: "123"