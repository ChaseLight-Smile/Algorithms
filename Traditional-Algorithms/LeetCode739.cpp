class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>ans(T.size(), 0);
        stack<int>s;
        for(int i = 0; i < T.size(); i++){
            while(!s.empty() && T[s.top()] < T[i]){
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};