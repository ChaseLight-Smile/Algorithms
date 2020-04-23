//cyclic sort
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        while(i < len){
            int j = nums[i];
            if(j < len && nums[i] != nums[j]){
                swap(nums[i], nums[j]);
            }else{
                ++i;
            }
        }
        for(int i = 0; i < len; i++){
            if(nums[i] != i){
                return i;
            }
        }
        return i;
    }
};