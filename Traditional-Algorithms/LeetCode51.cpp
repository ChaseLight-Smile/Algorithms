class Solution {
private:
    static const int N = 10;
    vector<string> one;
    vector<vector<string>> ans;
    bool col[N], diag[2*N-1], ndiag[2*N-1]; 
    int n ;
public:
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        for(int i = 0 ; i < n; i++){
            string tmp(n, '.');
            one.push_back(tmp);
        }
        dfs(0);
        return ans;
    }
    void dfs(int u){
        if(u == n){
            ans.push_back(one);
            return;
        }
        for(int i = 0; i <n ; i++){
            if(!col[i] && !diag[u+i] && !ndiag[u-i+n]){
                col[i] = diag[u+i] = ndiag[u-i+n] = true; 
                one[u][i] = 'Q';
                dfs(u+1);
                one[u][i] = '.';
                col[i] = diag[u+i] = ndiag[u-i+n] = false;
            }
        }
    }
    
};