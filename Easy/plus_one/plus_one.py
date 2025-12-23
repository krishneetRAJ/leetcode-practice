from typing import List

def plusOne(digits: List[int]) -> List[int]:
    i = len(digits) - 1
    while i >= 0:
        if digits[i] < 9:
            digits[i] += 1
            return digits
        digits[i] = 0
        i -= 1
    return [1] + digits

if __name__ == "__main__":
    print("Testing plusOne function:")
    print("For the input [1, 2, 3], the output is:", plusOne([1, 2, 3])) #Output: [1, 2, 4]
    print("For the input [4, 3, 2, 1], the output is:", plusOne([4, 3, 2, 1])) #Output: [4, 3, 2, 2]
    print("For the input [9], the output is:", plusOne([9])) #Output: [1, 0]