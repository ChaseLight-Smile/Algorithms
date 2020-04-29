struct cmp{
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[0] < b[0]){
            return true;
        }else if(a[0] > b[0]){
            return false;
        }else{
            return a[1] < b[1];
        }
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <= 1){
            return points.size();
        }
        sort(points.begin(), points.end(), cmp());
        vector<vector<int>> ans;
        ans.push_back(points[0]);
        
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] > ans.back()[1]){
                ans.push_back(points[i]);
            }else{
                ans.back()[0] = max(ans.back()[0], points[i][0]);
                ans.back()[1] = min(ans.back()[1], points[i][1]);
            }
        }
        return ans.size();
    }
};