class Solution {
private:
    vector<int> one;   //一个解
    vector<vector<int>> ans;  //全部解
    stack<vector<int>> st;  //保护现场
    int t;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return vector<vector<int>>();
        }
        t = target;
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int start){
        if(accumulate(one.begin(),one.end(),0) == t){
            ans.push_back(one);
            return;
        }
        if(accumulate(one.begin(),one.end(),0) > t){
            return;
        }
        for(int i = start; i < nums.size(); ++i){
            st.push(one);
            one.push_back(nums[i]);
            dfs(nums, i);
            one = st.top();
            st.pop(); 
        }
    }
};