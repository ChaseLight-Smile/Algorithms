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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }
        
        if(q!= nullptr && p != nullptr && p->val == q->val ){
            bool leftChildren = isSameTree(p->left, q->left);
            if(leftChildren){
                bool rightChildren = isSameTree(p->right, q->right);
                if(rightChildren){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else
            return false;
    }
};