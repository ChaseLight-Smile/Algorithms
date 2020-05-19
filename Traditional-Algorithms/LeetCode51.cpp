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


//从上到下，从左到右搜索
class Solution {
private:
    static const int N = 20;
    vector<string> one;
    vector<vector<string>> ans;
    bool row[N], col[N], diag[2*N-1], ndiag[2*N-1]; 
    int n ;
public:
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        for(int i = 0 ; i < n; i++){
            string tmp(n, '.');
            one.push_back(tmp);
        }
        
        dfs(0, 0, 0);
        return ans;
    }
    void dfs(int x , int y, int q){
        if(y == n){
            y = 0;
            x++;
        }  //转向
        if(x == n){
            if(q == n){
                ans.push_back(one);
                return;
            }
        }
        
        //当前位置不放皇后
        dfs(x, y+1, q);
        
        //当前位置放皇后
        if(!row[x] && !col[y] && !diag[x+y] && !ndiag[x-y+n]){
            one[x][y] = 'Q';
            row[x] = col[y] = diag[x+y] = ndiag[x-y+n] = true;
            dfs(x, y+1, q+1);
            row[x] = col[y] = diag[x+y] = ndiag[x-y+n] = false;
            one[x][y] = '.';
        }
    }
    
};