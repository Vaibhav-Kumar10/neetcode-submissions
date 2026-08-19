/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root, int& maxDiameter) {
        if(root == NULL) {
            return 0;
        }
        int left_diameter = dfs(root->left, maxDiameter);
        int right_diameter = dfs(root->right, maxDiameter);;
        maxDiameter = max(maxDiameter, left_diameter + right_diameter);
        return 1 + max(left_diameter, right_diameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int maxDiameter = 0;
        dfs(root, maxDiameter);
        return maxDiameter;
    }
};
