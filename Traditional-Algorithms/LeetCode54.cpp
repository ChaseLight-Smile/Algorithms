class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return {};
        }
        int upper = 0;
        int down = matrix.size()-1;
        int left = 0; 
        int right = matrix[0].size()-1;
        vector<int> ans;
        while(true){
            for(int i = left; i <= right; ++i) ans.push_back(matrix[left][i]);
            if(++upper > down) break;   //重设上边界
            for(int i = upper; i <= down; i++) ans.push_back(matrix[i][right]);
            if(--right < left) break;   //重设右边界
            for(int i = right; i >= left; i--)  ans.push_back(matrix[down][i]);
            if(--down < upper) break;  //重设下边界
            for(int i = down; i >= upper; i-- ) ans.push_back(matrix[i][left]);
            if(++left > right) break;//重设左边界 
        }
        return ans;
    }
};