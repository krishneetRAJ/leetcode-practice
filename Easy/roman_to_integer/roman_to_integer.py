from typing import List

def romanToInt(s: str) -> int:
    values = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    total = 0
    for i in range(len(s)):
        if (i+1 < len(s)) and (values[s[i]] < values[s[i+1]]):
            total -= values[s[i]]
        else:
            total += values[s[i]]
    return total

#Example usage: 
if __name__ == "__main__":
    print("Testing romanToInt function:")
    s1 = "III"
    print("For the input s1 'III', the integer value is:", romanToInt(s1)) #Output: 3

    s2 = "LVIII"
    print("For the input s2 'LVIII', the integer value is:", romanToInt(s2)) #Output: 58

    s3 = "MCMXCIV"
    print("For the input s3 'MCMXCIV', the integer value is:", romanToInt(s3)) #Output: 1994