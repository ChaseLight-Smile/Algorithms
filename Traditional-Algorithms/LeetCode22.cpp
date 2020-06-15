/*
    1. 任意前缀中左括号的数量>=右括号的数量，必须保证 
    2. 左右括号数量相等，显然成立
    3. 总共有多少种方案：结论是卡特兰数 C(2n, n)/(n+1) 因此时间复杂度为O( C(2n, n)/(n+1)*2n)
*/
class Solution {
private:
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
    void dfs(int n, int l, int r, string s){
        if(l == n && r == n) return ans.push_back(s);
        else{
            if(l < n) dfs(n, l+1, r, s + "(");
            if(r < n && l > r) dfs(n, l, r+1, s + ")");
        }
    }
};