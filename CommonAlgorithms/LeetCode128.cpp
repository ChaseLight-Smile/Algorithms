//解法一：时间溢出
class Solution {
    private:
    unordered_map<int, int> map;
public:
    int find_union(int x){
        if(map.find(x+1) != map.end()){
            map[x] = x+1;
        }
        if(map[x] == x){
            return x;
        }
        return map[x] = find_union(x+1);
    }
    
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = 0 ;
        for(i = 0 ; i < len; i++){
            map.insert({nums[i],nums[i]});
        }
        
        for (int i = 0 ; i < len; i++){
            find_union(nums[i]);
        }
        
        int ans = 0;
        for(auto & n : map){
            ans = max(ans, n.second - n.first + 1);
        }
        return ans;
    }
};