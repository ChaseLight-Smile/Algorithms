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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int result = 0;
        vector<vector<int>> ans = DFS(root);
        for(auto & n : ans){
            int sum = 0;
            for(auto & m: n){
                sum = sum*10+m;
            }
            result+=sum;
        }
        return result;
    }
    
    vector<vector<int>> DFS(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        
        vector<vector<int>> ans;
        vector<vector<int>> ans_left = DFS(root->left);
        vector<vector<int>> ans_right = DFS(root->right);
            
        if(root->left == nullptr && root->right == nullptr){
            return {{root->val}};
        }
        
        for(auto & l: ans_left){
            l.insert(l.begin(), root->val);
            ans.push_back(l);
        }
        
        for(auto & r: ans_right){
            r.insert(r.begin(), root->val);
            ans.push_back(r);
        }
        
        return ans;
    }
};