from typing import List

def removeInvalidParentheses(s: str) -> List[str]:
    result = []
    visited = set()
    queue = [s] # Initialize the queue with the original string
    visited.add(s)

    while queue:
        next = []
        for current in queue:
            balance = 0
            valid = True

            for char in current: #Check if parentheses are valid
                if char == '(':
                    balance += 1
                elif char == ')':
                    balance -= 1

                if balance < 0:
                    valid = False
                    break

            if balance != 0:
                valid = False
            if valid:
                result.append(current)

        #Stop once valid strings are found
        if result:
            return result

        #Remove one parenthesis at a time and add new strings to the queue
        for current in queue:
            for i in range(len(current)):
                if current[i] not in ('(', ')'):
                    continue
                new_str = current[:i] + current[i+1:]
                if new_str not in visited:
                    visited.add(new_str)
                    next.append(new_str)
        queue = next

    return result

if __name__ == "__main__":
    print("Testing removeInvalidParentheses function:")
    print("For the input '()())()', the output is:", removeInvalidParentheses("()())()"))  # Output: ["()()()", "(())()"]
    print("For the input '(a)())()', the output is:", removeInvalidParentheses("(a)())()"))  # Output: ["(a)()()", "(a())()"]
    print("For the input ')(', the output is:", removeInvalidParentheses(")("))  # Output: [""]