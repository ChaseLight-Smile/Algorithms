//sort+greedy
struct cmp{
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }else{
            return a[1] < b[1];
        }
    }    
};

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len <= 1){
            return len;
        }
        sort(intervals.begin(), intervals.end(), cmp());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 0; i<len; i++){
            if(intervals[i][0] > ans.back()[0] && intervals[i][1] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[0] = min(intervals[i][0], ans.back()[0]);
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans.size();
    }
};