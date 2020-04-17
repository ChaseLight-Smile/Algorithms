class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int p1=1,p2=1,i=nums.size()-1,n=nums.size()-1;
        sort(nums.begin(),nums.end());
        p1=nums[0]*nums[1]*nums[n];
        p2=nums[n]*nums[n-1]*nums[n-2];
        return max(p1,p2);
    }
};