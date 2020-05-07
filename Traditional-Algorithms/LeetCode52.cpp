class Solution {
    int ans, n;
    vector<bool> col, diag, ndiag;
public:
    int totalNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        diag = vector<bool>(2 * n);
        ndiag = vector<bool>(2 * n);
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