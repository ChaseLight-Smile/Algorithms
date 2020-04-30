struct queue_node{
    string str;
    int freq;
    queue_node(string x,int f): str(x), freq(f){}
};

struct cmp{
    bool operator()(queue_node* a, queue_node* b) const{
        if(a->freq < b->freq){
            return true;
        }else if(a->freq > b->freq){
            return false;
        }else{
            return a->str > b->str;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        int len = words.size();
        for(int i = 0 ; i < len; i++){
            if(m.find(words[i]) != m.end()){
                m[words[i]] = m[words[i]] + 1;
            }else{
                m[words[i]] = 1;
            }
        }
        
        priority_queue<queue_node*, vector<queue_node*>,cmp> q;
        for(auto & n : m){
            queue_node * tmp = new queue_node(n.first,n.second);
            q.push(tmp);
        }
        vector<string> ans;
        while(k > 0){
            queue_node* top = q.top();
            ans.push_back(top->str);
            q.pop();
            k--;
        }
        return ans;
    }
};