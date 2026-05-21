from typing import List

class MedianFinder:
    def __init__(self):
        self.nums = []

    def addNum(self, num: int) -> None:
        self.nums.append(num)
        self.nums.sort()

    def findMedian(self) -> float:
        n = len(self.nums)
        if n % 2 == 1:
            return float(self.nums[n // 2])
        else:
            return (self.nums[n // 2 - 1] + self.nums[n // 2]) / 2.0

if __name__ == "__main__":
    print("Testing MedianFinder class:")
    medianFinder = MedianFinder()
    output = [None]
    medianFinder.addNum(1)
    output.append(None)
    medianFinder.addNum(2)
    output.append(None)
    output.append(medianFinder.findMedian())
    medianFinder.addNum(3)
    output.append(None)
    output.append(medianFinder.findMedian())

    print(output)