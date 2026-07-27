#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result;
            if (!root) {
                return result;
            }

            vector<TreeNode*> currentLevel = {root};

            while (!currentLevel.empty()) {
                vector<int> currentValues;
                vector<TreeNode*> nextLevel;

                for (TreeNode* node : currentLevel) {
                    currentValues.push_back(node->val);
                    if (node->left) {
                        nextLevel.push_back(node->left);
                    }
                    if (node->right) {
                        nextLevel.push_back(node->right);
                    }
                }

                result.push_back(currentValues);
                currentLevel = nextLevel;
            }

            return result;
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

    vector<vector<int>> result1 = solution1.levelOrder(root1);
    cout << "Testing Binary Tree Level Order Traversal: " << endl;
    cout << "Input: [3, 9, 20, null, null, 15, 7]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "[";
        for (int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j];  
            if (j != result1[i].size() - 1) {
                    cout << ", ";
                }
        }
        cout << "]";
        if (i != result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    Solution solution2;
    TreeNode* root2 = new TreeNode(1);
    cout << "" << endl;
    vector<vector<int>> result2 = solution2.levelOrder(root2);
    cout << "Input: [1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "[";
        for (int j = 0; j < result2[i].size(); j++)
        {
            cout << result2[i][j];  
            if (j != result2[i].size() - 1) {
                    cout << ", ";
                }
        }
        cout << "]";
        if (i != result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    Solution solution3;
    TreeNode* root3 = nullptr;
    cout << "" << endl;
    vector<vector<int>> result3 = solution3.levelOrder(root3);
    cout << "Input: []" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << "[";
        for (int j = 0; j < result3[i].size(); j++)
        {
            cout << result3[i][j];
            if (j != result3[i].size() - 1) {
                    cout << ", ";
                }
        }
        cout << "]";
        if (i != result3.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}