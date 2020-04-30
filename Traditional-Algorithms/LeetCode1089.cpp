class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        int len = arr.size();
        for(int i = 0; i < len; i++){
            if(arr[i] == 0){
                if(ans.size() < len)
                    ans.push_back(arr[i]);
                if(ans.size() < len){
                    ans.push_back(0);
                }
            }else{
                if(ans.size() < len){
                    ans.push_back(arr[i]);
                }
            }
            if(ans.size() > len){
                break;
            }
        }
        arr = ans;
    }
};