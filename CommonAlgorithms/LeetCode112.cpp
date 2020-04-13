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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return false;
        }
        vector<int> ans = DFS(root);
        for(auto & n : ans){
            if(n == sum){
                return true;
            }
        }
        return false;
    }
    vector<int> DFS(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        vector<int>ans;
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back({root->val});
        }
        
        vector<int> sum_left = DFS(root->left);
        vector<int> sum_right = DFS(root->right);
        
        for(auto & l : sum_left){
            ans.push_back(root->val +l);
        }
        for(auto & r : sum_right){
            ans.push_back(root->val + r);
        }
        return ans;
    }
};