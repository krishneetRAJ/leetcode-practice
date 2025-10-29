from typing import List

def merge(self, intervals: List[List[int]]) -> List[List[int]]:
    #Sort the intervals
    intervals.sort()
    merged = [intervals[0]]
    for i in range(1, len(intervals)):
        if(intervals[i][0] <= merged[-1][1]):
            merged[-1][1] = max(merged[-1][1], intervals[i][1])
        else:
            merged.append(intervals[i])
    return merged

if __name__ == "__main__":
    print("Testing mergeIntervals function:")
    print("For the input [[1,3],[2,6],[8,10],[15,18]], the output is:", merge(None, [[1,3],[2,6],[8,10],[15,18]])) #Output: [[1,6],[8,10],[15,18]]
    print("For the input [[1,4],[4,5]], the output is:", merge(None, [[1,4],[4,5]])) #Output: [[1,5]]
    print("For the input [[1,4],[2,3]], the output is:", merge(None, [[1,4],[2,3]])) #Output: [[1,4]]