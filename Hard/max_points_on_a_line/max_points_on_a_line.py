from typing import List

def maxPoints(self, points: List[List[int]]) -> int:
    n = len(points)
    if n <= 2:
        return n
    max_points = 2

    for i in range(n):
        for j in range(i+1, n):
            count = 2 # points[i] and points[j] are already counted
            x1, y1 = points[i]
            x2, y2 = points[j]
            for k in range(n):
                if k == i or k == j:
                    continue
                x, y = points[k]
                # Check if points[i], points[j], and points[k] are collinear
                if (y2 - y1) * (x - x1) == (y - y1) * (x2 - x1):
                    count += 1
            if count > max_points:
                max_points = count
    return max_points

if __name__ == "__main__":
    print("Testing maxPoints function:")
    points = [[1,1],[2,2],[3,3]]
    print("For the input points =", points, ", the maximum number of points on a line is:", maxPoints(None, points))  # Expected output: 3

    points2 = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
    print("For the input points =", points2, ", the maximum number of points on a line is:", maxPoints(None, points2))  # Expected output: 4