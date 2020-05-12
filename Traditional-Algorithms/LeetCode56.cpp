struct cmp{
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[0] < b[0]){  //小于就是从小到大，跟heap的cmp相反
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len < 2){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        
        return ans;
    }
};


//POJ1089  AC  greedy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
vector<PII> range;

void merge(vector<PII>& range){
    vector<PII> ans;
    sort(range.begin(), range.end());  //sort提供对pair进行排序，默认按照first排序，如果first相同按照second排序
    
    int start = -2e9, end = -2e9;
    for(auto r : range){
        if(r.first > end){
            //说明两个区间没有交点
            start = r.first;
            end = r.second;
            if(start != -2e9) ans.push_back({start, end});
        }else{
            end = max(end, r.second);
        }
    }
    range = ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        int l , r;
        scanf("%d%d", &l, &r);
        range.push_back({l, r});
    }
    
    merge(range);
    printf("%d", range.size());
    return 0;
}