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
    void postorder(TreeNode* root, vector<int>& postorder_arr) {
        if(root == NULL) {
            return;
        }
        postorder(root->left, postorder_arr);
        postorder(root->right, postorder_arr);
        postorder_arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder_arr;
        postorder(root, postorder_arr);
        return postorder_arr;
    }
};