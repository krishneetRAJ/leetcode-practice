from typing import List

def reverse(x: int) -> int:
    INT_MIN, INT_MAX = -2**31, 2**31 - 1
    negative = False
    if x < 0:
        negative = True
        x = -x
    reverse_x = 0

    while x > 0:
        digit = x % 10
        reverse_x = reverse_x * 10 + digit
        x //= 10
    if negative:
        reverse_x = -reverse_x

    if reverse_x < INT_MIN or reverse_x > INT_MAX:
        return 0
    return reverse_x

# Example usage:
if __name__ == "__main__":
    print("Testing reverse function:")
    print("Reversing 123 gives:", reverse(123))  # Output: 321
    print("Reversing -123 gives:", reverse(-123))  # Output: -321
    print("Reversing 120 gives:", reverse(120))  # Output: 21