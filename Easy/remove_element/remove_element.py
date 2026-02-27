from typing import List

def removeElement(nums: List[int], val: int) -> int:
    i = 0
    for j in range(len(nums)):
        if nums[j] != val:
            nums[i] = nums[j]
            i += 1
    return i

if __name__ == "__main__":
    nums1 = [3,2,2,3]
    val1 = 3
    new_length1 = removeElement(nums1, val1)
    print(f"After removing {val1} from {nums1}, the new array is: {nums1[:new_length1]}")

    nums2 = [0,1,2,2,3,0,4,2]
    val2 = 2
    new_length2 = removeElement(nums2, val2)
    print(f"After removing {val2} from {nums2}, the new array is: {nums2[:new_length2]}")
