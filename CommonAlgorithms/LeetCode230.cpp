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
        if(root == nullptr){
            return 0;
        }
        int mid = countNode(root->left);
        if(k == mid+1){
            return root->val;
        }else if(k <= mid){
            return kthSmallest(root->left, k);
        }else{
            return kthSmallest(root->right, k-1-mid);
        }
    }
    
    int countNode(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        
        int leftCount = countNode(root->left);
        int rightCount = countNode(root->right);
        return 1+leftCount+rightCount;
    }
};