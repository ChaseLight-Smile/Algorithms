//dfs+backtracking
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


//位操作
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0 ; i < 1 << nums.size(); ++i){
            vector<int> tmp;
            for(int j = 0; j < nums.size(); ++j){
                if(i >> j & 1)
                    tmp.push_back(nums[j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};