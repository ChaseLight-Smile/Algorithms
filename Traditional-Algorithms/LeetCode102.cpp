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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> oneLevel;
            for(int i = q.size(); i>0 ;i--){
                TreeNode* current = q.front();
                q.pop();
                oneLevel.push_back(current->val);
                if(current->left != nullptr){
                    q.push(current->left);
                }

                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            ans.push_back(oneLevel);
        }
        return ans;
    }
};