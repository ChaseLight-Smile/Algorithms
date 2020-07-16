class Solution {
public:
    vector<int> get_factor(int n){
        vector<int>res;
        for(int i = 1; i <= n/i; i++){
            if(n % i == 0){
                res.push_back(i);
                if(i != n/i) res.push_back(n/i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    int kthFactor(int n, int k) {
        vector<int>ans = get_factor(n);
        if(k > ans.size()) return -1;
        return ans[k-1];
    }
};