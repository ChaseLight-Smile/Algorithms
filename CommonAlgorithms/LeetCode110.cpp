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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
		//求某个点的左右子树的高度
        int left =  heightTree(root->left);
        int right = heightTree(root->right);
        
		//一棵树为平衡二叉树的条件是：左右子树高度差为1，并且其子树也要平衡，即需要递归调用isBalanced(root->left) && isBalanced(root->right)
        if(abs(left - right) <=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
	
	//求某个节点的高度
    int heightTree(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
		//递归结束的出口，如果某个节点的左右节点都为空，说明其为叶子节点，我们规定叶子节点的高度为1
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
		
		//求左右子树的高度
        int leftHeight = heightTree(root->left);
        int rightHeight = heightTree(root->right);
        
		//某个节点的高度应该为其子树中最高的+1
        if(leftHeight < rightHeight){
            return 1+rightHeight;
        }
		//return max(leftHeight, rightHeight)+1;
        return 1+leftHeight;
    }
};