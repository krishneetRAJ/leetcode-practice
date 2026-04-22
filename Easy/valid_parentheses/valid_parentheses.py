from typing import List

def isValid(s: str) -> bool:
    stack = []
    for char in s:
        if char in "([{":
            stack.append(char)  
        else:
            # If stack is empty or the top of the stack doesn't match the corresponding opening bracket, return False
            if not stack:
                return False
            top = stack.pop()
            if char == ')' and top != '(':
                return False
            if char == ']' and top != '[':
                return False
            if char == '}' and top != '{':
                return False
            
    return len(stack) == 0  # If stack is empty, all brackets are valid

if __name__ == "__main__":
    print("Testing isValid function:")
    print("For the input '()', the output is:", isValid("()")) 
    print("For the input '()[]{}', the output is:", isValid("()[]{}"))
    print("For the input '(]', the output is:", isValid("(]"))
    print("For the input '([])', the output is:", isValid("([])"))
    print("For the input '([)]', the output is:", isValid("([)]"))