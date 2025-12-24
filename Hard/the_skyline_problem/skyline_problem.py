from typing import List
import heapq

def getSkyline(buildings: List[List[int]]) -> List[List[int]]:
    events = []
    for L, R, H in buildings:
        events.append((L, -H, R))  # start of building
        events.append((R, 0, 0))   # end of building

    # Sort after all events are added
    events.sort()

    result = []
    heap = [(0, float('inf'))]  # (-height, end_x)
    prev_max = 0

    for x, negH, R in events:
        # Remove buildings that ended
        while heap[0][1] <= x:
            heapq.heappop(heap)

        # If start event, add to heap
        if negH != 0:
            heapq.heappush(heap, (negH, R))

        # Current max height
        current_max = -heap[0][0]

        if current_max != prev_max:
            result.append([x, current_max])
            prev_max = current_max

    return result
    
if __name__ == "__main__":
    print("Testing skyline function:")
    buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
    print("For the input buildings =", buildings, ", the skyline is:", getSkyline(buildings))  # Expected output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]

    buildings2 = [[0,2,3],[2,5,3]]
    print("For the input buildings =", buildings2, ", the skyline is:", getSkyline(buildings2))  # Expected output: [[0,3],[5,0]]

