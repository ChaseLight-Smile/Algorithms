//wiki解
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        while(true){
            ans.push_back(nums);
            int i = nums.size()-1;
            while(i > 0 && nums[i-1] >= nums[i]){
                --i;
            }
            if(i == 0){
                break;
            }
            int j = nums.size()-1;
            while(j > i-1 && nums[j] <= nums[i-1]){
                --j;
            }
            swap(nums[i-1], nums[j]);
            reverse(nums.begin()+i, nums.end());
        }
        return ans;
    }
};


//dfs+backtracking+sort
class Solution {
private:
    vector<int> one;  //一个解，解变化之前，将之前的解放入stack中
    vector<vector<int>> ans;  //全部解
    stack<vector<int>>st; //保护现场
    vector<bool> visited; //是否被访问，可选
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0){
            return vector<vector<int>>();
        }
        sort(nums.begin(), nums.end());
        visited= vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int start){
        if(start == nums.size()){
            ans.push_back(one);
            return;
        }
        for(int i = 0 ; i < nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1])  continue;
            if(!visited[i]){
                visited[i] = true;
                st.push(one);   //保护现场
                one.push_back(nums[i]);
                dfs(nums, start+1);
                one = st.top(); //恢复现场
                st.pop();//恢复现场
                visited[i] = false;
            }
        }
    }
};