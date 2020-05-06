class Solution {
private:
    vector<int> one;   //一个解
    vector<vector<int>> ans;  //全部解
    stack<vector<int>> st;  //保护现场
    vector<bool>visited;  //访问位防止重复操作
    int t;
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return vector<vector<int>>();
        }
        t = target;
        sort(nums.begin(), nums.end());
        visited = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int start){
        if(start == nums.size() && accumulate(one.begin(),one.end(),0) != t){
            return;
        }
        if(accumulate(one.begin(),one.end(),0) == t){
            ans.push_back(one);
            return;
        }
        if(accumulate(one.begin(),one.end(),0) > t && start < nums.size()){
            return;
        }
        for(int i = start; i < nums.size(); ++i){
            if (i > start && nums[i] == nums[i-1]) continue;
            if(!visited[i]){
                st.push(one);
                visited[i] = true;
                one.push_back(nums[i]);
                dfs(nums, i+1);
                one = st.top();
                st.pop();
                visited[i] = false;
            }
        }
    }
};