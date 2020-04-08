//解法一 作弊解法，实际上是想用二分查找来写
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};