from typing import List

def addBinary(a: str, b: str) -> str:
    i = len(a) - 1
    j = len(b) - 1
    carry = 0
    result = ''

    while i >= 0 or j >= 0 or carry:
        total = carry
        if i >= 0:
            total += int(a[i])
            i -= 1
        if j >= 0:
            total += int(b[j])
            j -= 1

        carry = total // 2
        result = str(total % 2) + result

    return result

if __name__ == "__main__":
    print("Testing addBinary function:")
    print("For the input a = '11', b = '1', the output is:", addBinary('11', '1')) #Output: '100'
    print("For the input a = '1010', b = '1011', the output is:", addBinary('1010', '1011')) #Output: '10101'
    