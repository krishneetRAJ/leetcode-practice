from typing import List

def countMatchingSubarrays(nums: List[int], pattern: List[int]) -> int:
    count = 0
    n = len(nums)
    m = len(pattern)

    for i in range(n-m):
        match = True
        for j in range(m):
            if pattern[j] == 1 and nums[i + j + 1] <= nums[i + j]:
                match = False
                break

            elif pattern[j] == 0 and nums[i + j + 1] != nums[i + j]:
                match = False
                break

            elif pattern[j] == -1 and nums[i + j + 1] >= nums[i + j]:
                match = False
                break

        if match:
            count += 1

    return count

if __name__ == "__main__":
    print("Testing countMatchingSubarrays function:")
    print("For the input nums = [1, 2, 3, 4, 5, 6], pattern = [1, 1], the output is:", countMatchingSubarrays([1, 2, 3, 4, 5, 6], [1, 1]))
    print("For the input nums = [1, 4, 4, 1, 3, 5, 5, 3], pattern = [1, 0, -1], the output is:", countMatchingSubarrays([1, 4, 4, 1, 3, 5, 5, 3], [1, 0, -1])) 