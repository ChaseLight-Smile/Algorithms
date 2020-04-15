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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> left;
        vector<int> right;
        int len = preorder.size();
        if(len == 0){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < len; i++){
            if(preorder[i] < root->val){
                left.push_back(preorder[i]);
            }else{
                right.push_back(preorder[i]);
            }
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};