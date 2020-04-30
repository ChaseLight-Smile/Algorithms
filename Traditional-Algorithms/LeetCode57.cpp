//方法一，推倒全部重新排序
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


//解法二，利用了本身的排序特性，greedy的找到合适的插入点
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> ans;
        int i = 0;
        for(; i < intervals.size(); i++){
            if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                break;
            }else if(newInterval[0] <= intervals[i][1]){
                int left = min(newInterval[0], intervals[i][0]);
                int right = max(newInterval[1], intervals[i][1]);
                ans.push_back({left, right});
                break;
            }else{
                ans.push_back(intervals[i]);
            }
        }
        if(i >= intervals.size()){
            ans.push_back(newInterval);
        }else{
            for(int j = i+1; i < intervals.size(); ++i){
                if(ans.back()[1] < intervals[i][0]){
                    ans.push_back(intervals[i]);
                }else{
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]); 
                }
            }
        }
        
        return ans;
    }
};