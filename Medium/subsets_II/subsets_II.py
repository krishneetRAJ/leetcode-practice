from typing import List

def subsetsWithDup(nums: List[int]) -> List[List[int]]:
    nums.sort() # Sort the input to handle duplicates
    result = [[]] # Start with the empty subset
    start = 0 # This will track the starting index for the current number

    for i in range(len(nums)):
        if i > 0 and nums[i] == nums[i - 1]: # If the current number is the same as the previous one
            current_subsets = result[start:] # Only consider subsets generated from the last number
        else:
            current_subsets = result[:] # Consider all subsets generated so far
        start = len(result) # Update the starting index for the next number
        for subset in current_subsets:
            result.append(subset + [nums[i]]) # Add the current number to each of the current subsets

    return result

if __name__ == "__main__":
    print("Testing subsetsWithDup function:")
    print("For the input [1,2,2], the output is:", subsetsWithDup([1,2,2])) #Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    print("For the input [0], the output is:", subsetsWithDup([0])) #Output: [[],[0]]