class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto & m:grid){
            for(auto & n: m){
                if(n<0){
                    ans++;
                }
            }
        }
        return ans;
    }
};