#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
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
        vector<TreeNode*> generateTrees(int n) {
            vector<vector<vector<TreeNode*>>> trees(n+2, vector<vector<TreeNode*>>(n+2));
            for (int i = 1; i <= n+1; i++) {
                trees[i][i-1].push_back(nullptr);
            }
            for(int length = 1; length <= n; length++) {
                for(int start = 1; start <= n - length + 1; start++) {
                    int end = start + length - 1;
                    for(int root = start; root <= end; root++) {
                        for(TreeNode* left : trees[start][root-1]) {
                            for(TreeNode* right : trees[root+1][end]) {
                                TreeNode* node = new TreeNode(root);
                                node->left = left;
                                node->right = right;
                                trees[start][end].push_back(node);
                            }
                        }
                    }
                }
            }
            return trees[1][n];
        }
};

// Example usage:
int main() {
    Solution solution1;
    int n = 3;
    vector<TreeNode*> result = solution1.generateTrees(n);
    cout << "Testing Unique Binary Search Trees II: " << endl;
    cout << "Input: n = 3" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        // Serialize the tree for output
        vector<int> serializedTree;
        queue<TreeNode*> q;
        q.push(result[i]);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                serializedTree.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            } else {
                serializedTree.push_back(-1); // Use -1 to represent null
            }
        }
        // Remove trailing -1s
        while (!serializedTree.empty() && serializedTree.back() == -1) {
            serializedTree.pop_back();
        }
        for (size_t j = 0; j < serializedTree.size(); j++) {
            if (serializedTree[j] == -1) {
                cout << "null";
            } else {
                cout << serializedTree[j];
            }
            if (j != serializedTree.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "";
    Solution solution2;
    n = 1;
    result = solution2.generateTrees(n);
    cout << "" << endl;
    cout << "Input: n = 1" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        // Serialize the tree for output
        vector<int> serializedTree;
        queue<TreeNode*> q;
        q.push(result[i]);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                serializedTree.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            } else {    
                serializedTree.push_back(-1); // Use -1 to represent null
            }
        }
        // Remove trailing -1s
        while (!serializedTree.empty() && serializedTree.back() == -1) {
            serializedTree.pop_back();
        }
        for (size_t j = 0; j < serializedTree.size(); j++) {
            if (serializedTree[j] == -1) {
                cout << "null"; 
            } else {
                cout << serializedTree[j];
            }
            if (j != serializedTree.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}