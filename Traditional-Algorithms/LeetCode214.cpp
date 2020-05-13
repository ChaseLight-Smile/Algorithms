class Solution {
private:
    static const int N = 2e5+10;   //LeetCode的题目 都是1e5的长度，由于该题目要做拼接，所以为2倍大小
    int ne[N];
    char p[N];
public:
    string shortestPalindrome(string s) {
        // 拼接
        string t = s + "#" + string(s.rbegin(), s.rend());
        int n = t.size();
        for(int i = 1; i <= n; i ++){
            p[i] = t[i-1];
        }
        // 计算拼接串的next
        for(int i = 2, j = 0; i <= n; i++){
            while(j && p[i] != p[j+1]) j = ne[j];
            if(p[i] == p[j+1]) j++;
            ne[i] = j;
        }
        //重新拼接
        string sub = s.substr(ne[n]);
        reverse(sub.begin(), sub.end());
        string ans = sub + s;
        return ans;
    }
};