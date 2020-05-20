class Solution {
private:
    static const int N = 110;
    vector<vector<int>> grid;
    int d[N][N];
    queue<pair<int, int>>q;
    int n, m;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& _grid) {
        grid = _grid;
        n = grid.size();
        if(n == 0) return -1;
        m = grid[0].size();
        return bfs();
    }
    int bfs(){
        if(grid[0][0] == 1) return -1;
        q.push({0,0});
        memset(d, -1, sizeof(d));
        d[0][0] = 1;
        int dx[8] = {-1, -1, 0, 1,1,1,0,-1}, dy[8] = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            for(int i = 0 ; i < 8; i++){
                int x = t.first + dx[i], y = t.second + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && d[x][y] == -1){
                    d[x][y] = d[t.first][t.second] + 1;
                    q.push({x,y});
                }
            }
        }
        return d[n-1][m-1];
    }
};