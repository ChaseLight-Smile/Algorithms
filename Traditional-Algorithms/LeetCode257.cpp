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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<string> ans;
        TreeNode* current = root;
        if (current->left == nullptr && current->right == nullptr) return {to_string(current->val)};
        
        vector<string> ans_left = binaryTreePaths(current->left);
        vector<string> ans_right = binaryTreePaths(current->right);
        
        for(string l : ans_left){
            ans.push_back(to_string(current->val)+ "->" + l);
        }
        for(string r : ans_right){
            ans.push_back(to_string(current->val) + "->" + r);
        }
    
        return ans;
        
    }
};