class Solution {
    int ans, n;
    vector<bool> col, diag, ndiag;
public:
    int totalNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        diag = vector<bool>(2 * n - 1);  //  \表示主对角线 0, 1, 2..., 2n-2
        ndiag = vector<bool>(2 * n - 1);  // /表示副对角线 分为两个部分 （第一部分） 0, 1, 2, ..., n-1;  （第二部分）n-2, n-1, ... 0
        dfs(0);
        return ans;
    }
    void dfs(int start){
        if(start == n){
            ans++; 
            return;
        }
        for(int i = 0; i < n; ++i){
            if(!col[i] && !diag[start + i] && !ndiag[start - i + n]){
                col[i] = diag[start + i] = ndiag[start - i + n] = true;
                dfs(start+1);
                col[i] = diag[start + i] = ndiag[start - i + n] = false;
            }
        }
    }
};