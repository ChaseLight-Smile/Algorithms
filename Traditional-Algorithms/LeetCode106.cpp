/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int postLeft, int postRight){
        if(inLeft > inRight || postLeft > postRight) return nullptr;
        
        int i = 0 ;
        auto it = find(inorder.begin(), inorder.end(), postorder[postRight]);
        i = distance(begin(inorder), it);
        
        TreeNode* root = new TreeNode(postorder[postRight]);
        root->left = buildTree(inorder, inLeft, i-1, postorder, postLeft, postLeft - inLeft + i -1);
        root->right = buildTree(inorder, i+1, inRight, postorder, postLeft - inLeft + i, postRight-1);
        
        return root; 
    }
};