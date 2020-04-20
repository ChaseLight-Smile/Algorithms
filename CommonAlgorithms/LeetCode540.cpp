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