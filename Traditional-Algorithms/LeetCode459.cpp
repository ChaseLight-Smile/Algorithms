class Solution {
private:
    static const int N = 1e5;
    int ne[N];
    char p[N];
public:
    bool repeatedSubstringPattern(string s) {
        //求next数组即可
        int n = s.size();
        for(int i = 1; i <= n; i++){
            p[i] = s[i-1];
        }
        
        for(int i = 2, j = 0; i <= n; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }

        if(ne[n]== 0) return false;
        if(ne[n] % (n - ne[n]) == 0) return true;
        return false;
    }
};


//变形题，通过几次能够构造出原字符串
class Solution {
private:
    static const int N = 1e5;
    int ne[N];
    char p[N];
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i <= n; i++){
            p[i] = s[i-1];
        }
        
        for(int i = 2, j = 0; i <= n; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        
        if(ne[n] == 0) return false;
        else if(ne[n] % (n - ne[n]) == 0) {
            //cout << n / (n - ne[n]);  //输出重复构造的次数
            return true;
        }
        else return false;
    }
};