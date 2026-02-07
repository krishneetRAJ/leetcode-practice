from typing import List

def longest_consecutive(nums: List[int]) -> int:
    if not nums:
        return 0
    sorted_nums = sorted(set(nums))
    counter = 1
    maximum = 1
    for i in range(1, len(sorted_nums)):
        if sorted_nums[i-1] - sorted_nums[i] == -1:
            counter += 1
        elif sorted_nums[i-1] - sorted_nums[i] == 0:
            counter = counter + 0
        else:
            counter = 1
        if(counter > maximum):
            maximum = counter
    return maximum

#Example usage:
if __name__ == "__main__":
    print("Testing longest_consecutive function:")
    print("For the input nums = [100, 4, 200, 1, 3, 2], the output is:", longest_consecutive([100, 4, 200, 1, 3, 2])) #Output: 4
    print("For the input nums = [0,3,7,2,5,8,4,6,0,1], the output is:", longest_consecutive([0,3,7,2,5,8,4,6,0,1])) #Output: 9
    print("For the input nums = [1,2,0,1], the output is:", longest_consecutive([1,2,0,1])) #Output: 3