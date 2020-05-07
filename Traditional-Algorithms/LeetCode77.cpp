class Solution {
private:
    vector<int> one;  //一个解
    vector<vector<int>>ans; //全部解
    int count;  //一个解中的元素的个数
    vector<bool>visited;  //访问标志位
    stack<vector<int>>st;  //保护现场
public:
    vector<vector<int>> combine(int n, int k) {
        if(n == 0){
            return {};
        }
        count = k;
        visited = vector<bool>(count);
        vector<int> nums;
        for(int i = 1; i <= n; ++i){
            nums.push_back(i);
        }
        dfs(nums, 0);
        return ans;
    }
    
    void dfs(vector<int>& nums, int start){
        if(one.size() == count){
            ans.push_back(one);
            return;
        }
        
        for(int i = start ; i < nums.size(); ++i){
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