from typing import List

def reverseBits(n: int) -> int:
    result = 0
    for i in range(32):
        last_bit = n & 1
        result = result << 1
        result = result | last_bit
        n = n >> 1
    return result

if __name__ == "__main__":
    print("Testing reverseBits function:")
    n = 43261596
    print(f"For the input n = {n}, the output is: {reverseBits(n)}")

    n = 2147483644
    print(f"For the input n = {n}, the output is: {reverseBits(n)}")