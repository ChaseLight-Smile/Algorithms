struct queue_node{
    char c;
    int count;
    queue_node(char x, int y): c(x), count(y) {}
};

struct cmp{
    bool operator()(queue_node* a, queue_node* b){
        if(a->count < b->count){
            return true;
        }else if (a->count > b->count){
            return false;
        }else{
            return a->c > b->c;
        }
    }
};


class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
        unordered_map<char, int> m;
        for (int i = 0 ; i < len; i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]] = m[s[i]] + 1;
            }else{
                m[s[i]] = 1;
            }
        }
        
        priority_queue<queue_node*, vector<queue_node*>, cmp> q;
        for(auto & n : m){
            queue_node* tmp = new queue_node(n.first,n.second);
            q.push(tmp);
        }
        
        string ans;
        while(q.size() > 0){
            ans.append(q.top()->count, q.top()->c);
            q.pop();
        }
        return ans;
    }
};