#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            return 1 + max(leftDepth, rightDepth);
        }
};

// Example usage:
int main() {
    Solution solution1;
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    int result1 = solution1.maxDepth(root1);
    cout << "Input tree: [3,9,20,null,null,15,7]" << endl;
    cout << "Maximum depth of the first tree: " << result1 << endl;

    Solution solution2;
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    int result2 = solution2.maxDepth(root2);
    cout << endl;
    cout << "Input tree: [1,null,2]" << endl;
    cout << "Maximum depth of the second tree: " << result2 << endl;
    return 0;
}