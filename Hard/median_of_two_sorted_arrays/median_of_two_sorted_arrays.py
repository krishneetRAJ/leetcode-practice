from typing import List

def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
    merged = sorted(nums1 + nums2)
    n = len(merged)
    if(n % 2 == 1):
        return float(merged[n//2])
    else:
        return (merged[n//2 - 1] + merged[n//2]) / 2
    
if __name__ == "__main__":
    print("Testing findMedianSortedArrays function:")
    print("For the input [1, 3] and [2], the output is:", findMedianSortedArrays(None, [1, 3], [2])) #Output: 2.0
    print("For the input [1, 2] and [3, 4], the output is:", findMedianSortedArrays(None, [1, 2], [3, 4])) #Output: 2.5

