/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* current = root;
        if(current == nullptr){
            return NULL;
        }
        if(val == current->val){
            return current;
        }
        if(val < current->val){
            return searchBST(current->left,val);
        }else
            return searchBST(current->right,val);
    }
};