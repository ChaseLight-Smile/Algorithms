class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        int len = s.size();
        for(int i = 0 ; i < len; i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]] = m[s[i]]+1;
            }else{
                m[s[i]] = 1;
            }
        }
        
        for(int i = 0; i < len; i++){
            if(m[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};