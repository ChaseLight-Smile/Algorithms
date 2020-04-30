class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1)
            return len;
        int front = nums[0];
        int count = 1;
        for(int i = 1 ;i < nums.size();){
            if(nums[i] == front){
                nums.erase(nums.begin()+i);
                continue;
            }else{
                front = nums[i];
                i++;
            }
        }
        return nums.size();
    }
};