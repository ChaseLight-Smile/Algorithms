// hash table AC 但是不符合题意
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            if(m.find(nums[i]) != m.end())
                m[nums[i]] = m[nums[i]]+1;
            else
                m[nums[i]] = 1;
        }
        for(auto &n : m){
            if(n.second ==1){
                return n.first;
            }
        }
        return -1;
    }
};


//二分检索，O(1)空间复杂度 O(n)时间复杂度
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size(); 
        if(len == 0){
            return 0;
        }
        if(len == 1){
            return nums[0];
        }
        for(int i = 0; i < len-1;i++){
            int last = lastPosition(nums,nums[i],i+1, len-1);
            if(last == -1){
                return nums[i];
            }else{
                i = last;
            }
        }
        return nums[len-1];
    }
    
    int lastPosition(vector<int>& nums, int target, int start, int end){
        int left = start;
        int right = end;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        if(nums[left] == target){
            return left;
        }
        return -1;
       
    }
};