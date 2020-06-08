// 解法一: Manacher算法，时间复杂度为O(n),空间复杂度为O(n)
class Solution {
    static const int N = 1e3+10;
    char Ma[2 * N];
    int Mp[2 * N];
public:
    string longestPalindrome(string s) {
        int l = 0;
        int n = s.size();
        Ma[l++] = '$';
        Ma[l++] = '#';
        for(int i = 0; i < n; i++){
            Ma[l++] = s[i];
            Ma[l++] = '#';
        }
        Ma[l] = 0;
        int mx = 0, id = 0;
        for(int i = 0; i < l; i++){
            Mp[i] = mx > i? min(Mp[2*id-i],mx-i):1;
            while(i-Mp[i] >= 0 && i + Mp[i] < l && Ma[i+Mp[i]] == Ma[i-Mp[i]]) Mp[i]++; //数据加强，所以在这个部分要判断边界
            if(i + Mp[i] > mx){
                mx = i + Mp[i];
                id = i;
            }
        }
        
        //1. 取最长的回文串
        int ans = 0;
        for(int i = 0; i < 2 *n + 2; i++){
            ans = max(ans, Mp[i] - 1);
        }
        
        //2. 解出最长回文串
        string res;
        for(int i = 0 ; i < 2*n + 2; i++){
            if(Mp[i] == ans+1){
                for(int j = i - ans; j <= i + ans; j++){
                   if(Ma[j] != '#' && Ma[j] != '$'){
                       res+=Ma[j];
                   } 
                }
                break;  //最长回文串可能有多个，取出其中的一个即可停止
            }
        }
        return res;
    }
};


// 解法二: Manacher算法，时间复杂度为O(n),空间复杂度为O(n)，和解法一唯一的区别是在取最长回文子串时使用了substr函数
class Solution {
    static const int N = 1e3+10;
    char Ma[2 * N];
    int Mp[2 * N];
public:
    string longestPalindrome(string s) {
        int l = 0;
        int n = s.size();
        Ma[l++] = '$';
        Ma[l++] = '#';
        for(int i = 0; i < n; i++){
            Ma[l++] = s[i];
            Ma[l++] = '#';
        }
        Ma[l] = 0;
        int mx = 0, id = 0;
        for(int i = 0; i < l; i++){
            Mp[i] = mx > i? min(Mp[2*id-i],mx-i):1;
            while(i-Mp[i] >= 0 && i + Mp[i] < l && Ma[i+Mp[i]] == Ma[i-Mp[i]]) Mp[i]++;
            if(i + Mp[i] > mx){
                mx = i + Mp[i];
                id = i;
            }
        }
        
        //1. 取最长的回文串
        int ans = 0;
        for(int i = 0; i < 2 *n + 2; i++){
            ans = max(ans, Mp[i] - 1);
        }
        //2. 解出最长回文串
        string res;
        for(int i = 0 ; i < 2*n + 2; i++){
            if(Mp[i] == ans+1){
                res = s.substr(i-ans, ans);   //直接使用substr函数截取原字符串即可
                break;
            }
        }
        return res;
    }
};

//解法三：暴力搜索，时间复杂度为O(n^2)，空间复杂度O(1)，比DP的方法更节省空间，并且二者时间复杂度相同
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0 ; i < s.size(); i++){
            int l = i - 1, r = i + 1;  //枚举所有的奇数回文串
            while(l >= 0 && r < s.size() && s[l] == s[r]) l--,r++;
            if(res.size() < r - l -1) res = s.substr(l+1, r - l - 1);
        
            l = i, r = i+1; //枚举所有的偶数回文串
            while(l >= 0 && r < s.size() && s[l] == s[r]) l--,r++;
            if(res.size() < r - l -1) res = s.substr(l+1, r - l - 1);
        }
        return res;
    }
};