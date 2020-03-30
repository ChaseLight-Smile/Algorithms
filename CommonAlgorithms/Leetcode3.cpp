//解法一
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> hash;
        int len = s.size();
        int i = 0, j = 0, ans = 0;
        for(;i < len; i++){
            while (j < len && hash[s[j]] == false){
                hash[s[j]] = true;
                ans = max(ans, j-i+1);
                j++;
            }
            hash[s[i]] = false;
        }
        return ans;
    }
};


// 解法二
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256] = {0};
        int len = s.size();
        int i = 0, j = 0, ans = 0;
        for(;i < len; i++){
            while (j < len && map[s[j]] == 0 ){
                map[s[j]] = 1;
                ans = max(ans, j-i+1);
                j++;
            }
            map[s[i]] = 0;
        }
        return ans;
    }
};