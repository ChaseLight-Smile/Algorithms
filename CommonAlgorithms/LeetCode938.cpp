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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr){
            return 0;
        }
        vector<int> ans = inorderBST(root);
        int sum = 0 ;
        for(auto & n : ans){
            if(n >= L and n <= R){
                sum += n;
            }
        }
        return sum;
    }
    vector<int> inorderBST(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        
        vector<int> ans_left = inorderBST(root->left);
        vector<int> ans_right = inorderBST(root->right);
        
        ans_left.push_back(root->val);
        ans_left.insert(ans_left.end(), ans_right.begin(), ans_right.end());
        return ans_left;
    }
};