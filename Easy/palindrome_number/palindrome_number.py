from typing import List

def isPalindrome(x: int) -> bool:
    if (x < 0) or (x % 10 == 0 and x != 0):
        return False
    reversed_half = 0
    while x > reversed_half:
        reversed_half = reversed_half * 10 + x % 10
        x //= 10
    
    if x == reversed_half:
        return True
    
    if x == reversed_half // 10:
        return True
    
    return False

if __name__ == "__main__":
    print("Testing isPalindrome function:")
    print("For the input 121, the output is:", isPalindrome(121)) 
    print("For the input -121, the output is:", isPalindrome(-121))
    print("For the input 10, the output is:", isPalindrome(10))

