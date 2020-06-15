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

// 双指针改进
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int k = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]) nums[k++] = nums[i];
        }
        return k;
    }
};