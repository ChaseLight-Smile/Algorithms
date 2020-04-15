//解法一： unordered_multimap 44 / 45 test cases passed.
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
 
 //AC
 class TimeMap {
public:
    map<string, string> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        string combinedKey = key+to_string(timestamp);
        m.insert({combinedKey,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key+to_string(timestamp)) != m.end()){
            return m[key+to_string(timestamp)];
        }else{
            while(1){
                timestamp--;
                if(m.find(key+to_string(timestamp)) != m.end()){
                    return m[key+to_string(timestamp)];
                }
                if(timestamp == 1){
                    break;
                }
            }
            return "";
        }
       
    }
};


//解法三： unordered_map
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
 
 class TimeMap {
public:
    unordered_map<string, string> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        string combinedKey = key+to_string(timestamp);
        m.insert({combinedKey,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key+to_string(timestamp)) != m.end()){
            return m[key+to_string(timestamp)];
        }else{
            while(1){
                timestamp--;
                if(m.find(key+to_string(timestamp)) != m.end()){
                    return m[key+to_string(timestamp)];
                }
                if(timestamp == 1){
                    break;
                }
            }
            return "";
        }
       
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */