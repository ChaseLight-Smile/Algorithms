class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int,int>m;
        int len = nums.size() ;
        for(int i = 0 ; i < len; i++){
            m[nums[i]] = i;
        }
        
        if(m.find(target) != m.end()){
            return m[target];
        }
        return -1;
    }
};