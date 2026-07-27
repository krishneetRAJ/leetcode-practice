from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def levelOrder(root: Optional[TreeNode]) -> List[List[int]]:
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        level_size = len(queue)
        current_level = []

        for i in range(level_size):
            node = queue.pop(0)
            current_level.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(current_level)

    return result

# Example usage:
if __name__ == "__main__":
    print("Testing levelOrder function:")
    # Create a binary tree:
    #         3
    #        / \
    #       9  20
    #          / \
    #         15  7
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print("Input binary tree: ", "[3, 9, 20, Null, Null, 15, 7]")
    print("Level order traversal of the binary tree is:", levelOrder(root))  # Output: [[3], [9, 20], [15, 7]]
    print("")

    # Create another binary tree:
    #         1
    root = TreeNode(1)
    print("Input binary tree: ", "[1]")
    print("Level order traversal of the binary tree is:", levelOrder(root))  # Output: [[1]]
    print("")

    # Create another binary tree:
    #   []
    root = None
    print("Input binary tree: ", "[]")
    print("Level order traversal of the binary tree is:", levelOrder(root))  # Output: []
    print("")