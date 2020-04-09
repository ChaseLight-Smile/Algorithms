/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int> bstIterator;
    int current;
public:
    BSTIterator(TreeNode* root) {
        bstIterator = inOrder(root);
        current = -1;
    }
    
    /** @return the next smallest number */
    int next() {
        if(hasNext()){
            current = current + 1;
            return  bstIterator[current];
        }
        return 0;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        int len = bstIterator.size();
        if(current+1 < len) {
            return true;
        }else{
            return false;
        }
    }
    
    vector<int> inOrder(TreeNode* root){
        TreeNode* current = root;
        if(current == nullptr){
            return {};
        }
        
        vector<int>ans;
        vector<int>ans_left;
        vector<int>ans_right;
        if(current->left != nullptr){
            ans_left = inOrder(current->left);
        }
        ans.push_back(current->val);
        if(current->right != nullptr){
            ans_right = inOrder(current->right);
        }
        ans_left.insert(ans_left.end(), ans.begin(), ans.end());
        ans_left.insert(ans_left.end(), ans_right.begin(), ans_right.end());
        return ans_left;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */