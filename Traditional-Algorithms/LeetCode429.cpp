/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr){
            return {};
        }
        
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> tmp;
            for(int i = q.size(); i > 0; i--){
                Node* current = q.front();
                tmp.push_back(current->val);
                q.pop();
                for(auto & n : current->children){
                    q.push(n);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};