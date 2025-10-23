from typing import List #Import List because LeetCode has the function signature with List

def twoSum(nums: List[int], target: int) -> List[int]:
    num_to_index = {}
    for i, num in enumerate(nums):
        difference = target-num
        if difference in num_to_index:
            return [num_to_index[difference],i]
        num_to_index[num] = i

if __name__ == "__main__":
    print("Testing twoSum function:")
    print("For the input [2, 7, 11, 15] with target 9, the output is:", twoSum([2, 7, 11, 15], 9)) #Output: [0, 1]
    print("For the input [3, 2, 4] with target 6, the output is:", twoSum([3, 2, 4], 6)) #Output: [1, 2]
    print("For the input [3, 3] with target 6, the output is:", twoSum([3, 3], 6)) #Output: [0, 1]