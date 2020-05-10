class Solution {
private:
    static const int N = 10010;
    int s[N], a[N];
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 1; i <= nums.size(); i++){
            a[i] = nums[i-1];
        }
        for(int i = 1; i <= nums.size(); i++){
            s[i] = s[i-1] + a[i];
        }
        for(int i = 1; i <= nums.size()-1; i++){
            for(int j = i+1; j <= nums.size(); j++){
                int tmp = s[j] - s[i-1];
                if(k != 0 && tmp%k == 0){
                    return true;
                }
                if(k == 0 && tmp == k){
                    return true;
                }
            }
        }
        return false;
    }
};