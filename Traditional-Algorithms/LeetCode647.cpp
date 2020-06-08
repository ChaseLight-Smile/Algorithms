//暴力统计回文串的个数，枚举中心点，首先中心点是一个回文串，接着分别枚举奇数回文串和偶数回文串
class Solution {
public:
    int countSubstrings(string s) {
         int res = 0;
        for(int i = 0 ; i < s.size(); i++){
            res++;  // 1. 首先中心点是一个回文串
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l--, r++, res++;   //枚举奇数会回文串
            
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l--, r++, res++;   //枚举偶数回文串
        }
        return res;
    }
};