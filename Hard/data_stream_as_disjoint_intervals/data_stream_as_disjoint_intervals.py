from typing import List

class SummaryRanges:
    def __init__(self):
        self.intervals = []

    def addNum(self, value: int) -> None:
        new_intervals = []
        start = value
        end = value
        for interval in self.intervals:
            if interval[1] < start - 1: #Current interval comes before the new value
                new_intervals.append(interval)
            elif interval[0] > end + 1: #Current interval comes after the new value
                new_intervals.append([start, end])
                start = interval[0]
                end = interval[1]
            else: #Current interval overlaps with the new value
                start = min(start, interval[0])
                end = max(end, interval[1])
        new_intervals.append([start, end])
        self.intervals = new_intervals

    def getIntervals(self) -> List[List[int]]:
        return self.intervals

if __name__ == "__main__":
    print("Testing SummaryRanges class: ")
    summary_ranges = SummaryRanges()
    summary_ranges.addNum(1)
    print("After adding 1, intervals are:", summary_ranges.getIntervals()) #Output: [[1, 1]]
    summary_ranges.addNum(3)
    print("After adding 3, intervals are:", summary_ranges.getIntervals()) #Output: [[1, 1], [3, 3]]
    summary_ranges.addNum(7)
    print("After adding 7, intervals are:", summary_ranges.getIntervals()) #Output: [[1, 1], [3, 3], [7, 7]]
    summary_ranges.addNum(2)
    print("After adding 2, intervals are:", summary_ranges.getIntervals()) #Output: [[1, 3], [7, 7]]
    summary_ranges.addNum(6)
    print("After adding 6, intervals are:", summary_ranges.getIntervals ()) #Output: [[1, 3], [6, 7]]