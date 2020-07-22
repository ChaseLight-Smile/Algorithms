// 题目https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&&tqId=11217&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
    static const int N = 1e6+10;
    int q[N];
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int>ans;
        if(nums.size() == 1){
            ans.push_back(nums[0]);
            return ans;
        }
        if(nums.size() == 2){
            ans.push_back(max(nums[0], nums[1]));
            return ans;
        }
        
        int hh = 0, tt = -1;
        for(int i = 0; i < nums.size(); i++){
            if(hh <= tt && q[hh] < i- k + 1) hh++;
            while(hh <= tt && nums[q[tt]] < nums[i]) tt--;
            q[++tt] = i;
            if(i >= k-1) ans.push_back(nums[q[hh]]);
        }
        return ans;
    }
};