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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        if(current == nullptr){
            return {};
        }
        vector<int> ans;
        vector<int> ans_left;
        vector<int> ans_right;
        
        if(current->left != nullptr){
            ans_left = postorderTraversal(current->left);
        }
        if(current->right != nullptr){
            ans_right = postorderTraversal(current->right);
        }
        ans.push_back(current->val);
        ans_left.insert(ans_left.end(), ans_right.begin(),ans_right.end());
        ans_left.insert(ans_left.end(), ans.begin(), ans.end());
        return ans_left;
    }
};