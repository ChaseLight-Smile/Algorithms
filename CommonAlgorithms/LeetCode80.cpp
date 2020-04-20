class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2)
            return len;
        int front = nums[0];
        int count = 1;
        for(int i = 1 ;i < nums.size();){
            if(nums[i] == front && count < 2){
                count++;
                i++;
                continue;
            }else if(count == 2 && nums[i] == front){
                nums.erase(nums.begin()+i);
            }else{
                front = nums[i];
                count = 1;
                i++;
            }
        }
        return nums.size();
    }
};