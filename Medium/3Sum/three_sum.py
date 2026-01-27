from typing import List

def threeSum(nums: List[int]) -> List[List[int]]:
    nums.sort()
    result = []
    n = len(nums)

    for i in range(n - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue  # Skip duplicate values for the first number

        left, right = i + 1, n - 1
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            if total < 0:
                left += 1
            elif total > 0:
                right -= 1
            else:
                result.append([nums[i], nums[left], nums[right]])
                while left < right and nums[left] == nums[left + 1]:
                    left += 1  # Skip duplicate values for the second number
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1  # Skip duplicate values for the third number
                left += 1
                right -= 1

    return result

if __name__ == "__main__":
    print("Testing threeSum function:")
    print("For the input nums = [-1,0,1,2,-1,-4], the output is:", threeSum([-1,0,1,2,-1,-4]))  # Output: [[-1,-1,2],[-1,0,1]]
    print("For the input nums = [0,1,1], the output is:", threeSum([0,1,1]))  # Output: []
    print("For the input nums = [0,0,0], the output is:", threeSum([0,0,0]))  # Output: [[0,0,0]]