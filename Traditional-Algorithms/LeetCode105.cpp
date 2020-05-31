/** 一定要注意：题目强调了不存在重复的节点值，这也是寻找根节点的关键步骤
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, int preLeft, int preRight, vector<int> &inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight) return NULL;
        
        int i = 0;   //找到i即为inorder作为分界点
        // for (i = inLeft; i <= inRight; ++i) {
        //     if (preorder[pLeft] == inorder[i]) break; //这里的目的也是为了找i
        // }
        
        //使用vector的迭代器也能精确找到i的位置
        auto it = find(inorder.begin(), inorder.end(), preorder[preLeft]);
        i = distance(begin(inorder), it);
        
        TreeNode *root = new TreeNode(preorder[preLeft]);  //构造根节点
        root->left = buildTree(preorder, preLeft + 1, preLeft + i - inLeft, inorder, inLeft, i - 1);
        root->right = buildTree(preorder, preLeft + i - inLeft + 1, preRight, inorder, i + 1, inRight);
        return root;
    }
};