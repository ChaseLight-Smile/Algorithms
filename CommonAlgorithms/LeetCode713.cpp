class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        if(k<=1){
            return 0;
        }
        int i = 0;
        int count = 0;
        int product = 1;
        for(int j = 0; j < len; j++){
            product *= nums[j];
            while(product >= k){
                product /= nums[i];
                ++i;
            }
            count += j-i+1;
        }
        return count;
    }
};