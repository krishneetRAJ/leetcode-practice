from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxDepth(root: Optional[TreeNode]) -> int:
    if root is None:
        return 0
    else:
        return 1 + max(maxDepth(root.left), maxDepth(root.right)) #Doing this recursively to find the maximum depth of the binary tree.

if __name__ == "__main__":
    print("Testing maxDepth function:")
    # Example tree: [3, 9, 20, null, null, 15, 7]
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print("For the input [3, 9, 20, null, null, 15, 7], the output is:", maxDepth(root)) #Output: 3

    # Example tree: [1, null, 2]
    root2 = TreeNode(1)
    root2.right = TreeNode(2)
    print("For the input [1, null, 2], the output is:", maxDepth(root2)) #Output: 2
