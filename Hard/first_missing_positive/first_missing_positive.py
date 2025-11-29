from typing import List

def firstMissingPositive(self, nums: List[int]) -> int:
    n = len(nums)
    for i in range(n):
        if nums[i] <= 0:
            nums[i] = n + 1
    for i in range(n):
        num = abs(nums[i])
        if 1 <= num <= n:
            nums[num - 1] = -abs(nums[num - 1])
    for i in range(n):
        if nums[i] > 0:
            return i + 1
    return n + 1

if __name__ == "__main__":
    nums = [1, 2, 0]
    print("For the input: " + str(nums) + ", the first missing positive is: ", firstMissingPositive(None, nums))  # Output: 3

    nums = [3, 4, -1, 1]
    print("For the input: " + str(nums) + ", the first missing positive is: ", firstMissingPositive(None, nums))  # Output: 2

    nums = [7, 8, 9, 11, 12]
    print("For the input: " + str(nums) + ", the first missing positive is: ", firstMissingPositive(None, nums))  # Output: 1