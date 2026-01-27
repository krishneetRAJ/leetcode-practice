from typing import List

def divide(dividend: int, divisor: int) -> int:
    # Handle edge case
    if dividend == -2**31 and divisor == -1:
        return 2**31 - 1
    # Determine the sign of the result
    negative = False
    if (dividend < 0) ^ (divisor < 0):
        negative = True

    # Work with absolute values
    dividend, divisor = abs(dividend), abs(divisor)
    quotient = 0
    while dividend >= divisor:
        temp = divisor
        multiple = 1
        while dividend >= (temp << 1):
            temp <<= 1
            multiple <<= 1
        dividend -= temp
        quotient += multiple
    if negative:
        quotient = -quotient
    return quotient

# Example usage:
if __name__ == "__main__":
    solution1 = divide(10, 3)
    print("The result of dividing 10 by 3 is:", solution1)  # Output: 3
    solution2 = divide(7, -3)
    print("The result of dividing 7 by -3 is:", solution2)  # Output: -2


