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
    void preorder(TreeNode* root, vector<int>& preorder_arr) {
        if (root == NULL) {
            return;
        }
        preorder_arr.push_back(root->val);
        preorder(root->left, preorder_arr);
        preorder(root->right, preorder_arr);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder_arr;
        preorder(root, preorder_arr);
        return preorder_arr;
    }
};