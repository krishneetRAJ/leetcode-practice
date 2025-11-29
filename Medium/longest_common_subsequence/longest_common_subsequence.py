from typing import List 

def longest_common_subsequence(text1: str, text2: str) -> int:
    m = len(text1)
    n = len(text2)

    def lcs_recursive(i, j):
        if i==0 or j==0: #If either string is empty
            return 0
        if text1[i-1] == text2[j-1]: #If last characters match, add 1 to result and recurse for remaining strings
            return 1 + lcs_recursive(i-1, j-1)
        else: #If last characters don't match, recurse by excluding last character from either string
            return max(lcs_recursive(i-1, j), lcs_recursive(i, j-1))
        
    return lcs_recursive(m, n)

if __name__ == "__main__":
    print("Testing longest_common_subsequence function:")
    print("For the input text1 = 'abcde', text2 = 'ace', the output is:", longest_common_subsequence("abcde", "ace")) #Output: 3
    print("For the input text1 = 'abc', text2 = 'abc', the output is:", longest_common_subsequence("abc", "abc")) #Output: 3
    print("For the input text1 = 'abc', text2 = 'def', the output is:", longest_common_subsequence("abc", "def")) #Output: 0