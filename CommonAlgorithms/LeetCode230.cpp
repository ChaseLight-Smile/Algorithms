//Binary search tree inorder sort
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans = BSTSort(root);
        return ans[k-1];
    }
    
    vector<int> BSTSort(TreeNode* root){
        TreeNode* current = root;
        vector<int> ans;
        vector<int> ans_left;
        vector<int> ans_right;
        
        if(current == nullptr){
            return {};
        }
        
        ans_left = BSTSort(current->left);
        ans.push_back(current->val);
        ans_right = BSTSort(current->right);
        
        ans_left.insert(ans_left.end(), ans.begin(), ans.end());
        ans_left.insert(ans_left.end(), ans_right.begin(), ans_right.end());
        return ans_left;
    }
};