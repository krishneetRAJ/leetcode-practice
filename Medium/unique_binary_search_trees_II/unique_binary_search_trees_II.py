from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def generateTrees(n: int) -> List[Optional[TreeNode]]:
    if n == 0:
        return []

    trees = {}

    # Initialize empty subtrees
    for i in range(1, n + 2):
        trees[(i, i - 1)] = [None]

    for length in range(1, n + 1):
        for start in range(1, n - length + 2):
            end = start + length - 1
            result = []

            for root_val in range(start, end + 1):
                if root_val == start:
                    left_trees = [None]
                else:
                    left_trees = trees[(start, root_val - 1)]

                if root_val == end:
                    right_trees = [None]
                else:
                    right_trees = trees[(root_val + 1, end)]

                for left in left_trees:
                    for right in right_trees:
                        root = TreeNode(root_val)
                        root.left = left
                        root.right = right
                        result.append(root)

            trees[(start, end)] = result

    return trees[(1, n)]


def serialize(root: Optional[TreeNode]) -> List[Optional[int]]:
    if not root:
        return []

    result: List[Optional[int]] = []
    queue: List[Optional[TreeNode]] = [root]

    while queue:
        node = queue.pop(0)
        if node is None:
            result.append(None)
        else:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)

    while result and result[-1] is None:
        result.pop()

    return result

# Example usage:
if __name__ == "__main__":
    print("Testing generateTrees function:")
    n = 3
    result = generateTrees(n)
    output = [serialize(tree) for tree in result]
    print([["Null" if value is None else value for value in tree] for tree in output])

    print("")
    print("Testing generateTrees function with n = 1:")
    n = 1
    result = generateTrees(n)
    output = [serialize(tree) for tree in result]
    print([["Null" if value is None else value for value in tree] for tree in output])
    