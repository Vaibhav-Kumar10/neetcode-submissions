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
    void inorder(TreeNode* root, vector<int>& inorder_arr) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, inorder_arr);
        inorder_arr.push_back(root->val);
        inorder(root->right, inorder_arr);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder_arr;
        inorder(root, inorder_arr);
        return inorder_arr;
    }
};