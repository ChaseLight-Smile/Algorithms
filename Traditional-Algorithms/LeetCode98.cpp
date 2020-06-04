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
    bool isValidBST(TreeNode* root) {
    return dfs_valid(root, LONG_MIN, LONG_MAX);
}
    bool dfs_valid(TreeNode *root, long low, long high) {
        if (!root) return true;
        return low < root->val && root->val < high && dfs_valid(root->left, low, root->val)
            && dfs_valid(root->right, root->val, high);
    }
};