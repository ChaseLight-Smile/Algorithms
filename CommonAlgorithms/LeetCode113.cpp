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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> ans = levelOrder(root);
        vector<vector<int>> result;
        for(auto & m : ans){
            int target = 0 ;
            for(auto & n : m){
                target += n;
            }
            if(sum == target){
                result.push_back(m);
            }
        }
        return result;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        if(root->left == nullptr && root->right == nullptr){
            return {{root->val}};
        }
        
        vector<vector<int>> ans;
        vector<vector<int>> ans_left = levelOrder(root->left);
        vector<vector<int>> ans_right = levelOrder(root->right);
        
        for(auto & l : ans_left){
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