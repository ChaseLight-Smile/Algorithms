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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int len = intervals.size();
        if(len < 2){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i =  1; i < len; i++){
            if(ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};