from typing import List
import json

def summaryRanges(nums: List[int]) -> List[str]:
    result = []

    i = 0
    while i < len(nums):
        start = nums[i]
        while (i+1 < len(nums)) and (nums[i+1] == nums[i] + 1):
            i += 1
        end = nums[i]
        if start == end:
            result.append(str(start))
        else:
            result.append(f"{start}->{end}")
        i += 1

    return result

if __name__ == "__main__":
    print("Testing summaryRanges function:")
    print("For the input [0,1,2,4,5,7], the output is:", json.dumps(summaryRanges([0,1,2,4,5,7]))) #Output: ["0->2","4->5","7"]
    print("For the input [0,2,3,4,6,8,9], the output is:", json.dumps(summaryRanges([0,2,3,4,6,8,9]))) #Output: ["0","2->4","6","8->9"]