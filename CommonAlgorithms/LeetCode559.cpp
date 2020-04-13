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
    int maxDepth(Node* root) {
        if(root == nullptr){
            return 0;
        }
        queue<Node*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){
                Node* current = q.front();
                q.pop();
                if(!current->children.empty()){
                    for(auto & n : current->children){
                        q.push(n);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};