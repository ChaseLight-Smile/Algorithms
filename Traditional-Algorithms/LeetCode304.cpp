class NumMatrix {
private:
    static const int N = 1e4+10;
    int s[N][N], a[N][N];
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m;
        if(n == 0)
            m = 0;
        else
            m = matrix[0].size();
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = matrix[i-1][j-1];
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = s[row2+1][col2+1] - s[row2+1][col1] - s[row1][col2+1] + s[row1][col1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
 
 
 //改进版本的prefix sum
class NumMatrix {
private:
    vector<vector<int>>s;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m;
        if(n == 0)
            m = 0;
        else
            m = matrix[0].size();
        s = vector(n+1, vector<int>(m+1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = s[row2+1][col2+1] - s[row2+1][col1] - s[row1][col2+1] + s[row1][col1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */