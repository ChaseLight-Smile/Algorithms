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
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        vector<vector<int>> result = DFS(root);
        if(result.size() == 0){
            return 0;
        }
        int ans = result[0].size();
        for(int i = 1; i < result.size(); i++){
            if(result[i].size() < ans){
                ans = result[i].size();
            }
        }
        return ans;
    }
    
    vector<vector<int>> DFS(TreeNode* root){
        if(root == nullptr)
            return {};
        
        if(root->left == nullptr && root->right == nullptr){
            return {{root->val}};
        }
        
        vector<vector<int>> ans_left = DFS(root->left);
        vector<vector<int>> ans_right = DFS(root->right);
        
        vector<vector<int>> ans;
        for(auto & l : ans_left){
            l.insert(l.begin(), root->val);
            ans.push_back(l);
        }
        for(auto & r : ans_right){
            r.insert(r.begin(), root->val);
            ans.push_back(r);
        }
        return ans;
    }
};