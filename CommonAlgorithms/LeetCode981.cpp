//解法一： unordered_multimap
struct ValueNode{
    string value;
    int timestamp;
    ValueNode();
    ValueNode(string v, int t): value(v), timestamp(t){};
};

class TimeMap {
public:
    unordered_multimap<string, ValueNode> mmp;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        mmp = {};
    }
    
    void set(string key, string value, int timestamp) {
        ValueNode v = ValueNode(value,timestamp);
        mmp.insert({key,v});
    }
    
    string get(string key, int timestamp) {
        auto n = mmp.count(key);
        string ans ;
        if(n == 1){
            ValueNode current = mmp.find(key)->second;
            if(current.timestamp <= timestamp){
                return current.value;
            }else{
                return nullptr;
            }
        }else if (n>1){
            auto m = mmp.equal_range(key);
            int max = INT_MIN;
            while(m.first != m.second){
                if(m.first->second.timestamp <= timestamp){
                    if(m.first->second.timestamp > max){
                        max = m.first->second.timestamp;
                        ans= m.first->second.value;
                    }
                }
                ++m.first;
            }
            return ans;
        }
        return nullptr;
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */