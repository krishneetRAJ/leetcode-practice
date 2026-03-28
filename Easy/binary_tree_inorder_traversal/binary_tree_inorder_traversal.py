from typing import List

def inorderTraversal(root) -> List[int]:
    if root is None:
        return []
    
    result = []
    stack = []
    current = root

    while current is not None or stack:
        while current is not None:
            stack.append(current)
            current = current.left
        
        current = stack.pop()
        result.append(current.val)
        current = current.right

    return result

if __name__ == "__main__":
    print("Testing inorderTraversal function:")
    # Example tree: [1, null, 2, 3]
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)

    print("For the input [1, null, 2, 3], the output is:", inorderTraversal(root)) #Output: [1, 3, 2]

    # Example tree: [1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9]
    root2 = TreeNode(1)
    root2.left = TreeNode(2)
    root2.right = TreeNode(3)
    root2.left.left = TreeNode(4)
    root2.left.right = TreeNode(5)
    root2.right.right = TreeNode(8)
    root2.left.right.left = TreeNode(6)
    root2.left.right.right = TreeNode(7)
    root2.right.right.left = TreeNode(9)

    print("For the input [1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9], the output is:", inorderTraversal(root2)) #Output: [4, 2, 6, 5, 7, 1, 3, 9, 8]

    # Example tree: []
    print("For the input [], the output is:", inorderTraversal(None)) #Output: []

    # Example tree: [1]
    root3 = TreeNode(1)
    print("For the input [1], the output is:", inorderTraversal(root3)) #Output: [1]

    