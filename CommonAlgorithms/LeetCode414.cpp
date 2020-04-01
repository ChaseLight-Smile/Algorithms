class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int, int> map;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            map.insert({nums[i],0});
        }
        priority_queue<int, vector<int>, less<int>> q;
        for(const auto & n : map){
            q.push(n.first);
        }
        
        int k = 3;
        int ans;
        if(q.size() < 3){
            return q.top();
        }
        while(k > 0){
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};