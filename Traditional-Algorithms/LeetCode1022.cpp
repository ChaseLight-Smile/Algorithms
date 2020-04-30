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
    int sumRootToLeaf(TreeNode* root) {
        vector<vector<int>> ans = DFS(root);
        int totalSum = 0;
        for(auto & n : ans){
            int sum = 0 ;
            for(auto m : n){
                sum = sum*2 + m;
            }
            totalSum += sum;
        }
        return totalSum;
    }
    vector<vector<int>> DFS(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        
        //当你碰到根节点的时候，那么此时就应该返回了
        if(root->left == nullptr && root->right == nullptr){
            return {{root->val}};
        }
        vector<vector<int>> ans;
        vector<vector<int>> ans_left = DFS(root->left);
        vector<vector<int>> ans_right = DFS(root->right);
        //ans = [[1,0,0],[1,0,1]] 
        for(auto  n : ans_left){
            n.insert(n.begin(), root->val);
            ans.push_back(n);
        }
        //[[1,1,0],[1,1,1]]
        for(auto  m : ans_right){
            m.insert(m.begin(), root->val);
            ans.push_back(m);
        }
        return ans;
    }
};