class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        int len = nums.size();
        for(int i = 0 ; i< len;i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]] = m[nums[i]]+1;
            }else{
                m[nums[i]] = 1;
            }
        }
        vector<int> ans ;
        for(auto &n : m){
            if(n.second == 1){
                ans.push_back(n.first);
            }
        }
        return ans;
    }
};