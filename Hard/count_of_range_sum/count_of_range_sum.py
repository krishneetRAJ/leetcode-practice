from typing import List

def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
    prefix = [0]
    for num in nums:
        prefix.append(prefix[-1] + num)

    def sort(low, high):
        if(high-low <= 1):
            return 0
        mid = (low + high) // 2
        count = sort(low, mid) + sort(mid, high)
        j = k = mid
        for i in range(low, mid):
            while k < high and prefix[k] - prefix[i] < lower:
                k += 1
            while j < high and prefix[j] - prefix[i] <= upper:
                j += 1
            count += (j - k)
        temp = []
        left, right = low, mid
        while left < mid and right < high:
            if(prefix[left] < prefix[right]):
                temp.append(prefix[left])
                left += 1
            else:
                temp.append(prefix[right])
                right += 1

        while left < mid:
            temp.append(prefix[left])
            left += 1
        while right < high:
            temp.append(prefix[right])
            right += 1
        prefix[low:high] = temp
        return count
    
    return sort(0, len(prefix))

if __name__ == "__main__":
    print("Testing countRangeSum function:")
    print("For the input nums = [-2, 5, -1], lower = -2, upper = 2, the output is:", countRangeSum(None, [-2, 5, -1], -2, 2)) #Output: 3
    print("For the input nums = [0], lower = 0, upper = 0, the output is:", countRangeSum(None, [0], 0, 0)) #Output: 1