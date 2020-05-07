class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        int i,j;
        for(i = 1; i <= n; ++i){
            s += to_string(i);
        }
        if(k == 1){
            return s;
        }
        k--;
        while(k>0){
            i = s.size()-1;
            while(i > 0 && s[i-1] >= s[i]){
                --i;
            }
            int j = s.size()-1;
            while(j > i-1 && s[j] <= s[i-1]){
                --j;
            }
            swap(s[i-1], s[j]);
            reverse(s.begin()+i, s.end());
            k--;
        }
        return s;
    }
};



//backtracking
class Solution {
    string s; // 一个解
    vector<string>ans; //所有解
    stack<string>st; //保护现场
    vector<bool>visited;
    int count;
public:
    string getPermutation(int n, int k) {
        if(n == 0){
            return nullptr;
        }
        vector<int>nums;
        count = k;
        for(int i = 1; i <= n; ++i){
            nums.push_back(i);
        }
        visited = vector<bool>(n);
        dfs(nums, 0);
        return ans[k-1];
    }
    void dfs(vector<int>& nums, int start){
        if(start == nums.size()){
            ans.push_back(s);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!visited[i]){
                visited[i] = true;
                st.push(s);
                s += to_string(nums[i]);
                dfs(nums, start+1);
                s = st.top();
                st.pop();
                visited[i] = false;
            } 
        }
    }
};