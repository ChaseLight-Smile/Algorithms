class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>m;
        for(int i = 0; i < nums1.size(); i++){
            m[nums1[i]] = i;
        }
        vector<int> ans(nums1.size(), -1);
        stack<int> s;
        for(int i = 0 ; i < nums2.size(); i++){
            while(!s.empty() && s.top()<nums2[i]){
                int tmp = s.top();
                s.pop();
                if(m.find(tmp) != m.end()){
                    ans[m[tmp]] = nums2[i];
                }
            }
            s.push(nums2[i]);
        }
        return ans;
    }
};