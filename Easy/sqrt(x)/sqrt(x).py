from typing import List

def mySqrt(x: int) -> int:
    if x < 2:
        return x
    left, right, answer = 1, x, 0
    while left <= right:
        mid = (left + right) // 2
        if(mid * mid) == x:
            return mid
        elif(mid * mid) < x:
            left = mid + 1
            answer = mid
        else:
            right = mid - 1
    return answer

if __name__ == "__main__":
    print("Testing mySqrt function:")
    print("For the input 4, the output is:", mySqrt(4)) #Output: 2
    print("For the input 8, the output is:", mySqrt(8)) #Output: 2
