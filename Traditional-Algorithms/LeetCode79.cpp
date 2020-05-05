class Solution {
    int dx[4] ={-1,0,1,0}, dy[4] = {0, 1, 0, -1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0){
            return false;
        }
        for(int i = 0 ; i < board.size(); ++i){
            for(int j = 0 ; j < board[0].size(); ++j){
                if(dfs(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int x, int y, string word, int u){
        if(board[x][y] != word[u]){
            return false;
        }
        if(u == word.size()-1){
            return true;
        }
        board[x][y] = '.';   //将该状态置为原始矩阵中不存在的值，防止重复查找
        for(int i = 0 ; i < 4; ++i){
            int a = x + dx[i];
            int b = y + dy[i];
            if(a >= 0 && a < board.size() && b >= 0 && b < board[0].size()){
                if(dfs(board, a, b, word, u+1)){
                    return true;
                }
            }
        }
        
        board[x][y] = word[u]; //在结束查找之后，一定要恢复该位的状态，保证回溯的时的状态一致
        
        return false;
    }
};