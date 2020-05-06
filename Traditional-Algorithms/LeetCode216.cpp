class Solution {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<int> one; //一个解
    vector<vector<int>>ans;  //所有解
    stack<vector<int>> st;
    vector<bool>visited;
    int target;
    int count;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n == 0){
            return vector<vector<int>>();
        }
        count = k;
        target = n;
        visited = vector<bool>(count);
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int start){
        if(accumulate(one.begin(), one.end(), 0) == target && one.size() == count){
            ans.push_back(one);
            return;
        }
        for(int i = start; i <nums.size(); ++i){
            if(i > start && nums[i] == nums[i-1])
                continue;
            if(!visited[i]){
                visited[i] = true;
                st.push(one);
                one.push_back(nums[i]);
                dfs(nums, i+1);
                one = st.top();
                st.pop();
                visited[i] = false;
            }
        }
    }
};