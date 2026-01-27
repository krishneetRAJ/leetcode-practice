from typing import List

def minWindow(s: str, t: str) -> str:
    if not t or not s:
            return ""
    
    dict_t = {}
    for c in t:
        dict_t[c] = dict_t.get(c, 0) + 1 # Count characters in t using a dictionary
    window_counts = {}
    required = len(dict_t)
    formed = 0
    l = 0
    min_len = float("inf")
    min_start = 0

    for r in range(len(s)):
        character = s[r]
        window_counts[character] = window_counts.get(character, 0) + 1

        if character in dict_t and window_counts[character] == dict_t[character]:
            formed += 1

        while l <= r and formed == required:
            if (r - l + 1) < min_len:
                min_len = r - l + 1
                min_start = l

            left_char = s[l]
            window_counts[left_char] -= 1

            if left_char in dict_t and window_counts[left_char] < dict_t[left_char]:
                formed -= 1

            l += 1

    result = ""
    if min_len != float("inf"):
        result = s[min_start:min_start + min_len]

    return result 

# Example usage:
Solution1 = minWindow(s = "ADOBECODEBANC", t = "ABC")
print("With the string 'ADOBECODEBANC' and target 'ABC', the minimum window substring is:", Solution1)  # Output: "BANC"
Solution2 = minWindow(s = "a", t = "a")
print("With the string 'a' and target 'a', the minimum window substring is:", Solution2)  # Output: "a"
Solution3 = minWindow(s="a", t="aa")
print("With the string 'a' and target 'aa', the minimum window substring is:", repr(Solution3)) # Output: ""