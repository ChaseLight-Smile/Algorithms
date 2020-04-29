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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        if(intervals.size() <= 1){
            return 0;
        }
        vector<int> pre = intervals[0];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][1] <= pre[1] && intervals[i][0] >= pre[0]){
                pre[0] = intervals[i][0];
                pre[1] = intervals[i][1];
                count++;
            }else if(intervals[i][0] < pre[1] && intervals[i][1] > pre[1]){
                count++;
            }else{
                pre[0] = intervals[i][0];
                pre[1] = intervals[i][1];
            }
        }
        return count;
    }
};