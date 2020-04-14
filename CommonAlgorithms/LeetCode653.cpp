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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr){
            return false;
        }
        vector<int> ans = inorder(root);
        int len = ans.size();
        for(int i = 0 ; i < len-1; i++){
            if(i>0 && ans[i] == ans[i-1]) continue;
            int left = i+1;
            while(left < len){
                if(ans[i] + ans[left] == k){
                    return true;
                }
                left++;
            }
        }
        return false;   
    }
    vector<int> inorder(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        vector<int> ans_left = inorder(root->left);
        vector<int> ans_right = inorder(root->right);
        
        ans_left.insert(ans_left.end(),root->val);
        ans_left.insert(ans_left.end(), ans_right.begin(), ans_right.end());
        
        return ans_left;
    }
};


//下面代码中result结果中输出了所有等于k的组合数。
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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr){
            return false;
        }
        vector<int> ans = inorder(root);
        vector<vector<int>> result;
        
        int len = ans.size();
        bool flag = false;
        for(int i = 0 ; i < len-1; i++){
            if(i>0 && ans[i] == ans[i-1]) continue;
            int left = i+1;
            vector<int> tmp ;
            while(left < len){
                if(ans[i] + ans[left] == k){
                    flag = true;
                    tmp.push_back(ans[i]);
                    tmp.push_back(ans[left]);
                }
                while(i > 0 && ans[left] == ans[left+1]) left++;
                left++;
            }
            result.push_back(tmp);
        }
        for(auto & m : result){
            for(auto & n: m){
                cout << n << " ";
            }
        }
        return flag;   
    }
    vector<int> inorder(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        vector<int> ans_left = inorder(root->left);
        vector<int> ans_right = inorder(root->right);
        
        ans_left.insert(ans_left.end(),root->val);
        ans_left.insert(ans_left.end(), ans_right.begin(), ans_right.end());
        
        return ans_left;
    }
};