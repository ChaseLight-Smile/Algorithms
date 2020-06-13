class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() == 0) return res;
        for(int i = 0; ;i++){
            if(i >= strs[0].size()) return res;
            char c = strs[0][i];
            for(auto& str: strs){
                if(i >= str.size() || str[i] != c) return res;
            }
            res += c;
        }
        return res;
    }
};