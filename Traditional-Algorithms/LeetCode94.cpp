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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        vector<int> ans;
        vector<int> ans_left;
        if(current == nullptr){
            return {};
        }
        if(current->left != nullptr){
            ans_left = inorderTraversal(current->left);
        }
        
        ans.push_back(current->val);
        ans_left.insert(ans_left.end(), ans.begin(),ans.end());
        vector<int> ans_right;
        if(current->right != nullptr){
             ans_right = inorderTraversal(current->right);
        }
        ans_left.insert(ans_left.end(), ans_right.begin(), ans_right.end());
        return ans_left;
    }
};