class Solution {
private:
    static const int N = 1e6+10;
    char s[N], p[N];
    int ne[N];
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(n == 0 && m == 0){
            return 0;
        }
        
        if(n != 0 && m == 0){
            return 0;
        }
        
        for(int i = 1; i <= n; i++){
            s[i] = haystack[i-1];
        }
        for(int i = 1; i <= m; i++){
            p[i] = needle[i-1];
        }
        
        //计算next
        for(int i = 2, j = 0; i <= m; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        
        //计算匹配的位置
        for(int i = 1, j = 0; i <= n; i++){
            while(j && s[i] != p[j+1]) j = ne[j];
            if(s[i] == p[j+1]) j++;
            if(j == m){
                //匹配成功
                return i - m;
            }
        }
        return -1;
    }
};