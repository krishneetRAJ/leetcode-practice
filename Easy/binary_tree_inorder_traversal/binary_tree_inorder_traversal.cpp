#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            if(root == nullptr) {
                return result;
            }
            vector<int> left = inorderTraversal(root->left);
            result.insert(result.end(), left.begin(), left.end());
            result.push_back(root->val); // Add the current node's value
            vector<int> right = inorderTraversal(root->right);
            result.insert(result.end(), right.begin(), right.end());
            return result;
        }
};

// Example usage:
int main() {
    Solution solution1;
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);
    vector<int> result1 = solution1.inorderTraversal(root1);
    cout << "Inorder Traversal of the first tree: ";
    cout << "[";
    for(int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if(i < result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    Solution solution2;
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->right = new TreeNode(8);
    root2->left->right->left = new TreeNode(6);
    root2->left->right->right = new TreeNode(7);
    root2->right->right->left = new TreeNode(9);
    vector<int> result2 = solution2.inorderTraversal(root2);
    cout << "Inorder Traversal of the second tree: ";
    cout << "[";
    for(int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if(i < result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    Solution solution3;
    TreeNode* root3 = nullptr; // Empty tree
    vector<int> result3 = solution3.inorderTraversal(root3);
    cout << "Inorder Traversal of the empty tree: ";
    cout << "[";
    for(int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if(i < result3.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    Solution solution4;
    TreeNode* root4 = new TreeNode(1); // Single node tree
    vector<int> result4 = solution4.inorderTraversal(root4);
    cout << "Inorder Traversal of the single node tree: ";
    cout << "[";
    for(int i = 0; i < result4.size(); i++) {
        cout << result4[i];
        if(i < result4.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}