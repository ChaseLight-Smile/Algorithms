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
    int maxLevelSum(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return 0;
        }
        ans = levelOrder(root);
        int maxima = ans[0];
        int result = 0;
        for(int i = 1 ; i < ans.size(); i++){
            if(ans[i] >= maxima){
                maxima = ans[i];
                result = i+1;
            }
        }
        return result;
    }
    
    vector<int> levelOrder(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sum = 0;
            for(int i = q.size(); i>0; i--){
                TreeNode* current = q.front();
                q.pop();
                sum += current->val;
                if(current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};