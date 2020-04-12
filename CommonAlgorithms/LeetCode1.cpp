//解法一： hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            m[nums[i]] = i;
        }
        vector<int>ans;
        for(int i = 0 ; i < len; i++){
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};

//解法二：loop
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans;
        bool flag = false;
        for(int i = 0 ; i < len; i++){
            for(int j = i; j < len; j++){
                if(nums[i] + nums[j] == target && i != j){
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = true;
                    break;
                }
            }
            if (flag == true){
                break;
            }
        }
        return ans;
    }
};