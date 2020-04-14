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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int max = INT_MIN; 
            for(int i = q.size(); i >0; i--){
                TreeNode* current = q.front();
                q.pop();
                if(current->val > max){
                    max = current->val;
                }
                if(current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            ans.push_back(max);
        }
        return ans;
    }
};