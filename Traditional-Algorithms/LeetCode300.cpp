//DP，时间复杂度为O(n^2)
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

//贪心，时间复杂度为O(nlogn)
class Solution {
    static const int N = 1e4+10;
    int f[N]; // 表示长度为i的子序列的结尾元素的最小值
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int l = 0, r = res;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(f[mid] < nums[i]) l = mid;
                else r = mid-1;
            }
            res = max(res, r+1);
            f[r+1] = nums[i];
        }
        return res;
    }
};