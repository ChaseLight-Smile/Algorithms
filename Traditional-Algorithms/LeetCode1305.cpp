//解法一： BFS
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        if(root1 == nullptr && root2 != nullptr){
            vector<int> tmp = levelTranversal(root2);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        if(root2 == nullptr && root1 != nullptr){
            vector<int> tmp = levelTranversal(root1);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        
        if(root2 != nullptr && root1 != nullptr){
            vector<int> tmp1 = levelTranversal(root1);
            vector<int> tmp2 = levelTranversal(root2);
            ans.insert(ans.end(), tmp1.begin(), tmp1.end());
            ans.insert(ans.end(), tmp2.begin(), tmp2.end());
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> levelTranversal(TreeNode* root){
        if (root == nullptr){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            ans.push_back(current->val);
            q.pop();
            if(current->left!= nullptr){
                q.push(current->left);
            }
            if(current->right != nullptr){
                q.push(current->right);
            }
        }
        return ans;
    }
};

//解法二： DFS
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        if(root1 == nullptr && root2 != nullptr){
            vector<int> tmp = DFS(root2);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        if(root2 == nullptr && root1 != nullptr){
            vector<int> tmp = DFS(root1);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        
        if(root2 != nullptr && root1 != nullptr){
            vector<int> tmp1 = DFS(root1);
            vector<int> tmp2 = DFS(root2);
            ans.insert(ans.end(), tmp1.begin(), tmp1.end());
            ans.insert(ans.end(), tmp2.begin(), tmp2.end());
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> DFS(TreeNode* root){
        if (root == nullptr){
            return {};
        }
        TreeNode* current = root;
        vector<int> ans;
        vector<int> ans_left;
        vector<int> ans_right;
        
        ans_left = DFS(current->left);
        ans.push_back(current->val);
        ans_right = DFS(current->right);
        ans_left.insert(ans_left.end(), ans.begin(), ans.end());
        ans_left.insert(ans_left.end(), ans_right.begin(), ans_right.end());
        return ans_left;
    }
};