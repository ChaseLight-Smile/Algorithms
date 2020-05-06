class Solution {
    vector<int> one = {};
    vector<vector<int>> ans;
    stack<vector<int>> st;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        dfs(nums, 0);
        return ans;
    }
    
    void dfs(vector<int>& nums, int start){
        ans.push_back(one);
        
        for(int i = start; i < nums.size(); ++i){
            st.push(one);
            one.push_back(nums[i]);
            dfs(nums, i+1);
            one = st.top();
            st.pop();
        }
    }
};