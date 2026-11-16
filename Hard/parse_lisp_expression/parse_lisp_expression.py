from typing import List

def evaluate(expression: str) -> int:
    return solve(expression, {})

#Helper function
def solve(expr, variables):
    if expr[0] != '(':
        if expr[0] == '-' or expr[0].isdigit():
            return int(expr)
        return variables[expr]

    expr = expr[1:-1]
    parts = []
    current = ""
    depth = 0

    # Split expression into parts
    for char in expr:
        if char == '(':
            depth += 1
        elif char == ')':
            depth -= 1

        if char == ' ' and depth == 0:
            parts.append(current)
            current = ""
        else:
            current += char

    parts.append(current)
    operation = parts[0]

    if operation == "add":
        return solve(parts[1], variables) + solve(parts[2], variables)

    if operation == "mult":
        return solve(parts[1], variables) * solve(parts[2], variables)

    if operation == "let":
        variables = variables.copy()
        for i in range(1, len(parts) - 1, 2):
            variables[parts[i]] = solve(parts[i + 1], variables)

        return solve(parts[-1], variables)

if __name__ == "__main__":
    print("Testing evaluate function:")
    print("For the input expression = '(let x 2 (mult x (let x 3 y 4 (add x y))))', the output is:", evaluate('(let x 2 (mult x (let x 3 y 4 (add x y))))')) #Output: 14
    print("For the input expression = '(let x 3 x 2 x)', the output is:", evaluate('(let x 3 x 2 x)')) #Output: 2
    print("For the input expression = '(let x 1 y 2 x (add x y) (add x y))', the output is:", evaluate('(let x 1 y 2 x (add x y) (add x y))')) #Output: 5