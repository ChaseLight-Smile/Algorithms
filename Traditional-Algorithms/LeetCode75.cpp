//解法一： 作弊解法，不推荐
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};


//解法二 两趟算法 O(n)时间复杂度,O(n)空间复杂度
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans_0;
        vector<int> ans_1;
        vector<int> ans_2;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(0 == nums[i]){
                ans_0.push_back(0);
            }
            if(1 == nums[i]){
                ans_1.push_back(1);
            }
            if(2 == nums[i]){
                ans_2.push_back(2);
            }
        }
        ans_0.insert(ans_0.end(), ans_1.begin(), ans_1.end());
        ans_0.insert(ans_0.end(), ans_2.begin(), ans_2.end());
        nums = ans_0;
    }
};

//解法三 两趟算法，空间复杂度为O(1) 时间复杂度为O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_0 = 0 ;
        int count_1 = 0 ;
        int count_2 = 0 ;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            if(0 == nums[i]){
                count_0++;
            }
            if(1 == nums[i]){
                count_1++;
            }
            if(2 == nums[i]){
                count_2++;
            }
        }
        
        for(int i = 0 ; i < count_0; i++){
            nums[i] = 0;
        }
        for(int i = count_0 ; i < count_0+count_1; i++){
            nums[i] = 1;
        }
        for(int i = count_0+count_1 ; i < count_0+count_1+count_2; i++){
            nums[i] = 2;
        }
    }
};

//解法四 一趟算法，时间复杂度为O(n) 空间复杂度为O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1){
            return;
        }
        vector<int> countNums(nums.size()+1);
        for(int i = 0 ; i < nums.size(); i++){
            countNums[nums[i]] += 1;
        }
        nums.clear();
        for(int i = 0; i < countNums.size(); i++){
            if(countNums[i] > 0){
                int count = countNums[i];
                while(count > 0){
                    nums.push_back(i);
                    count--;
                }
            }
        }
    }
};