from typing import List

def lengthOfLastWord(s: str) -> int:
    if not s:
        return 0
    chunks = s.split()
    if not chunks:
        return 0
    return len(chunks[-1])

if __name__ == "__main__":
    print("Testing lengthOfLastWord function:")
    test_case_1 = "Hello World"
    print(f"For the input '{test_case_1}', the output is:", lengthOfLastWord(test_case_1)) #Output: 5

    test_case_2 = "   fly me   to   the moon  "
    print(f"For the input '{test_case_2}', the output is:", lengthOfLastWord(test_case_2)) #Output: 4

    test_case_3 = "luffy is still joyboy"
    print(f"For the input '{test_case_3}', the output is:", lengthOfLastWord(test_case_3)) #Output: 6