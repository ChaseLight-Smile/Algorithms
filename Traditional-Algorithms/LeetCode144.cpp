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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        vector<int> ans;
        if(current == nullptr){
            return {};
        }
        ans.push_back(current->val);
        vector<int> ans_left = preorderTraversal(current->left);
        vector<int> ans_right = preorderTraversal(current->right);
        
        ans.insert(ans.end(),ans_left.begin(),ans_left.end());
        ans.insert(ans.end(),ans_right.begin(),ans_right.end());
        return ans;
    }
};