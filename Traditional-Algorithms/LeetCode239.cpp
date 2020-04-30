//解法一： multiset
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        
        multiset<int> s;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            s.insert(nums[i]);
        }
        auto it = s.end();
        ans.push_back(*--it);
        int left = 0;
        
        for(int i = k ; i < len; i++){
            auto pos = s.find(nums[left]);  
            s.erase(pos);
            s.insert(nums[i]);
            auto it = s.end();
            ans.push_back(*--it);
            left++;
        }
        return ans;
    }
};

