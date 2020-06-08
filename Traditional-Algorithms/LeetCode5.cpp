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
        for(int i = 1; i < l; i++){
            Mp[i] = mx > i? min(Mp[2*id-i],mx-i):1;
            while(Ma[i+Mp[i]] == Ma[i-Mp[i]]) Mp[i]++;
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
                break;
            }
        }
        return res;
    }
};