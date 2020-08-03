class Solution {
    static const int N = 1e4+10;
    int f[N]; // 表示当前以i为结尾的上升子序列长度
public:
    int lengthOfLIS(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            f[i] = 1;
            for(int j = 0; j <= i; j++){
                if(nums[j] < nums[i]) f[i] = max(f[i], f[j]+1);
            }
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++) res = max(res, f[i]);
        return res;
    }
};