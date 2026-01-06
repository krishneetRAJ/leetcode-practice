from typing import List

def majorityElement(nums: List[int]) -> int:
    count = 0
    for num in nums:
        if count == 0:
            majority = num
        if num == majority:
            count += 1
        else:
            count -= 1
    return majority

if __name__ == "__main__":
    print("Testing majorityElement function:")
    nums1 = [3,2,3]
    print("For the input nums1[3, 2, 3], the majority element is:", majorityElement(nums1)) #Output: 3

    nums2 = [2,2,1,1,1,2,2]
    print("For the input nums2[2, 2, 1, 1, 1, 2, 2], the majority element is:", majorityElement(nums2)) #Output: 2
