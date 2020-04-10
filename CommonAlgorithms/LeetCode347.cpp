//解法一 hash+heap
struct queue_node{
    int key;
    int count;
    queue_node(int x, int y): key(x), count(y){}
};

struct cmp{
    bool operator()(queue_node* a, queue_node* b) const{
        return a->count < b->count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]] = m[nums[i]] + 1;
            }else{
                m[nums[i]] = 1;
            }
        }
        
        priority_queue<queue_node*, vector<queue_node*>,cmp> q;
        for(auto & n: m){
            queue_node * tmp = new queue_node(n.first,n.second);
            q.push(tmp);
        }

        vector<int> ans;
        while(k > 0){
            queue_node* top = q.top();
            ans.push_back(top->key);
            q.pop();
            k--;
        }
        return ans;
    }
};

//解法二 双map
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        map<int,int>::iterator m_it;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]] = m[nums[i]]+1;
            }else{
                m[nums[i]] = 1;
            }
        }
        
        multimap<int, int> ans;
        map<int, int>::reverse_iterator mm_it;
        for(m_it = m.begin(); m_it!= m.end(); m_it++){
            ans.insert(pair<int, int>(m_it->second, m_it->first));
        }
        
        
        vector<int> result;
        for(mm_it = ans.rbegin(); mm_it!= ans.rend(), k>0; mm_it++){
            result.push_back(mm_it->second);
            k--;
        }
        
        return result;
        
    }
};

//解法三：hash+map
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]] = m[nums[i]]+1;
            }else{
                m[nums[i]] = 1;
            }
        }
        
        multimap<int, int> ans;
        map<int, int>::reverse_iterator mm_it;
        for(auto & m_it: m){
            ans.insert(pair<int, int>(m_it.second, m_it.first));
        }
        
        
        vector<int> result;
        for(mm_it = ans.rbegin(); mm_it!= ans.rend(), k>0; mm_it++){
            result.push_back(mm_it->second);
            k--;
        }
        
        return result;
        
    }
};