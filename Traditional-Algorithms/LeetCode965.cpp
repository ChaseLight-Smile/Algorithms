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
    bool isUnivalTree(TreeNode* root) {
        set<int> s;
        if(root == nullptr){
            return false;
        }
        set<int> ans = levelOrder(root);
        if(ans.size() == 1){
            return true;
        }
        return false;
    }
    set<int> levelOrder(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        set<int> ans;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            ans.insert(current->val);
            if(current->left != nullptr){
                q.push(current->left);
            }
            if(current->right != nullptr){
                q.push(current->right);
            }
        }
        return ans;
    }
};