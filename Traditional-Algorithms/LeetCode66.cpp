class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        vector<int> ans;
        int ddd = 0;
        ans.push_back((digits[len-1] + ddd + 1) % 10);
        ddd = (digits[len-1] + ddd + 1) / 10;
        
        for(int i = len-2; i >= 0; i--){
            ans.push_back((digits[i] + ddd) % 10);
            ddd = (digits[i] + ddd) / 10;
        }
        if(ddd == 1){
            ans.push_back(1);
        }
        
        int ans_len = ans.size();
        if (ans_len % 2  == 0){
            for(int i = 0 ; i <= (ans_len -1)/2; i++){
                int tmp = ans[i];
                ans[i] = ans[ans_len-1-i];
                ans[ans_len-1-i] = tmp;
            }
        }else{
            for(int i = 0 ; i < (ans_len -1)/2; i++){
                int tmp = ans[i];
                ans[i] = ans[ans_len-1-i];
                ans[ans_len-1-i] = tmp;
            }
        }
        return ans;
    }
};