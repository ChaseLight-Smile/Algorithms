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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> tmp;
            for(int i = q.size(); i > 0; i--){
                TreeNode* current = q.front();
                q.pop();
                if(level%2 == 0){
                    tmp.push_back(current->val);
                }else{
                    tmp.insert(tmp.begin(),current->val);
                }
                if(current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            ans.push_back(tmp);
            level++;
        }
        return ans;
    }
};