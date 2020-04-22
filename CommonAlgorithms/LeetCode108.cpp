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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size()-1);
    }
    TreeNode* BST(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BST(nums, left, mid-1);
        root->right = BST(nums, mid+1, right);
        return root;
    }   
};